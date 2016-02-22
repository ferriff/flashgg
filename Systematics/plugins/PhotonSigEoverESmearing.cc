#include "flashgg/Systematics/interface/ObjectSystMethodBinnedByFunctor.h"
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/Common/interface/PtrVector.h"
#include "flashgg/DataFormats/interface/Photon.h"
#include "CommonTools/Utils/interface/StringCutObjectSelector.h"

namespace edm {
    class Event;
}

namespace flashgg {

    class PhotonSigEoverESmearing: public ObjectSystMethodBinnedByFunctor<flashgg::Photon, int>
    {

    public:
        typedef StringCutObjectSelector<Photon, true> selector_type;

        PhotonSigEoverESmearing( const edm::ParameterSet &conf );
        void applyCorrection( flashgg::Photon &y, int syst_shift, const edm::Event & ev ) override;
        std::string shiftLabel( int ) const override;

    private:
        selector_type overall_range_;
    };

    PhotonSigEoverESmearing::PhotonSigEoverESmearing( const edm::ParameterSet &conf ) :
        ObjectSystMethodBinnedByFunctor( conf ),
        overall_range_( conf.getParameter<std::string>( "OverallRange" ) )
    {
        if (!applyCentralValue()) throw cms::Exception("SmearingLogic") << "If we do not apply central smearing we cannot scale down the smearing";
    }

    std::string PhotonSigEoverESmearing::shiftLabel( int syst_value ) const
    {
        std::string result;
        if( syst_value == 0 ) {
            result = Form( "%s", label().c_str() );
        }
       // else if( syst_value > 0 ) {
       //     result = Form( "%sUp%.2dsigma", label().c_str(), syst_value );
       // } else {
       //     result = Form( "%sDown%.2dsigma", label().c_str(), -1 * syst_value );
       // }
        return result;
    }

    void PhotonSigEoverESmearing::applyCorrection( flashgg::Photon &y, int syst_shift, const edm::Event & ev )
    {
        if( overall_range_( y ) ) {
            auto val_err = binContents( y );
            if( val_err.first.size() == 1 && val_err.second.size() == 1 ) { // otherwise no-op because we don't have an entry
                float shift_val = val_err.first[0];  // e.g. 0 if no central value change
                float shift_err = val_err.second[0]; // e.g. 0.1
                float shift = shift_val + syst_shift * shift_err;
                //              std::vector<edm::Ptr<reco::Vertex> > keys;
                if( debug_ ) {
                    std::cout << "  " << shiftLabel( syst_shift ) << ": Photon has pt= " << y.pt() << " eta=" << y.eta()
                              << " and we apply a sigmaEoverE smearing of " << shift << std::endl;
                    std::cout << "shift_val: " << shift_val << ", shift_err: " << shift_err << ", syst_shift: " << syst_shift <<std::endl;
                    std::cout << "     sigE/E VALUE BEFORE: ";
                    auto beforeSigEoE = y.sigEOverE();
                    std::cout << beforeSigEoE << " ";
                    std::cout << std::endl;
                }
                y.addUserFloat("unsmaeraedSigmaEoE", y.sigEOverE() );
                y.smearSigmaEOverEValueBy( shift ); 
                // the others are no longer used at this stage anyway, so it cannot hurt
                if ( debug_) {
                    auto afterSigEoE = y.sigEOverE();
                    std::cout << "     sigE/E VALUE AFTER: ";
                    std::cout << afterSigEoE << " ";
                    std::cout << std::endl;
                }
            }
        }
    }
    
}
    
DEFINE_EDM_PLUGIN( FlashggSystematicPhotonMethodsFactory,
                   flashgg::PhotonSigEoverESmearing,
                   "FlashggPhotonSigEoverESmearing" );
// Local Variables:
// mode:c++
// indent-tabs-mode:nil
// tab-width:4
// c-basic-offset:4
// End:
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4

