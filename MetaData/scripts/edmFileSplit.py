#!/usr/bin/env python

import optparse
import os
import sys

def write_cfg(ofile, iroot_file, oroot_file, ls_list = "[]"):
    of = open(ofile, "w")
    of.write("""import FWCore.ParameterSet.Config as cms
import FWCore.Utilities.FileUtils as FileUtils
process = cms.Process("splitter")
process.load("FWCore.MessageService.MessageLogger_cfi")
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32( 1000 )
process.MessageLogger.cerr.threshold = 'ERROR'
""")
    of.write('process.out = cms.OutputModule("PoolOutputModule",fileName = cms.untracked.string("' + oroot_file + '"))\n')
    of.write('process.source = cms.Source("PoolSource",fileNames=cms.untracked.vstring("' + iroot_file + '"), lumisToProcess=cms.untracked.VLuminosityBlockRange(' + str(ls_list) + '))\n')
    of.write('process.e = cms.EndPath(process.out)\n')


def lumi_json(ifile):
    print "getting lumis for file", ifile
    runsLumisDict = {}
    lumis = Lumis (ifile)
    delivered = recorded = 0
    for lum in lumis:
        runList = runsLumisDict.setdefault (lum.aux().run(), [])
        runList.append( lum.aux().id().luminosityBlock() )
    jsonList = LumiList (runsAndLumis = runsLumisDict)
    return jsonList.getCompactList()
    #if options.output:
    #    jsonList.writeJSON(options.output)


def nlumis(json_list):
    cnt = 0
    for k in json_list.keys():
        for ls in json_list[k]:
            for i in range(ls[0], ls[1] + 1):
                cnt += 1
    return cnt


def split_lumis(json_list, sfact):
    lumilist = []
    for k in json_list.keys():
        for ls in json_list[k]:
            for i in range(ls[0], ls[1] + 1):
                lumilist.append([k, i])
    lumilist.sort(key = lambda x: x[0])
    print lumilist
    v, l = [], []
    for rl in lumilist:
        if len(l) and len(l) % sfact == 0:
            #print l
            v.append(l)
            l = []
        l.append(rl)
    return v
    #lumilist.sort()
    #s = "[%d, " % lumilist[0]
    #lastlumi = lumilist[0]
    ##for i in range(len(lumilist) - 1):
    #v = []
    #for ls in lumilist[1:]:
    #    cnt += 1
    #    print cnt, ls, s
    #    if ls != lastlumi + 1:
    #        s += "%d], " % lastlumi
    #        opened = False
    #    if cnt % sfact == 0:
    #        if opened:
    #            s += "%d], " % lastlumi
    #            opened = False
    #        v.append(s.rstrip(','))
    #        s = ""
    #    if not opened:
    #        s += "[%d, " % ls
    #    lastlumi = ls
    #    opened = True
    #for el in v:
    #    print el
    #return v
            

def split_file(ifile, lumilist):
    cnt = 1
    for ll in lumilist:
        print ll
        root = os.path.basename(ifile).replace(".root", "_split%d" % cnt)
        write_cfg('cfg_job_' + root + '.py', ifile, root + '.root', LumiList(lumis = ll).getCMSSWString().split(','))
        cnt += 1


parser = optparse.OptionParser ("Usage: %prog [--options] edm1.root [edm2.root...]",
                            description='Runs over input EDM files and prints out a list of contained lumi sections')
parser.add_option ('-i', dest='ifile', type='string', default = "",
               help='input file (comma-separated list)')
parser.add_option ('-s', dest='sfact', type='int', default = 1,
               help='split factor (i.e. 1 file is splitted into SFACT ones)')
(options, args) = parser.parse_args()

ifile_list = list(options.ifile.split(","))

print ifile_list

if ifile_list[0] == '':
    parser.print_usage()
    sys.exit(1)


from DataFormats.FWLite import Lumis, Handle
from FWCore.PythonUtilities.LumiList import LumiList


if not parser.has_option('-i'):
    ifile_list = list(options.ifile.split(","))
sfact = options.sfact

for ifile in ifile_list:
    ls = lumi_json(ifile)
    nls = nlumis(ls)
    sfact = int(nls / options.sfact) + 1
    slumis = split_lumis(ls, sfact)
    split_file(ifile, slumis)
