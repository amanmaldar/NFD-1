#include "global.hpp"

using namespace std;
namespace nfd {
namespace cs {

	

		const char *path="/home/lenovo/Dropbox/Thesis/Logs/minindn3/status_2.txt";
		std::ofstream ofs;

		void sayHello(){
		return;
			ofs.open (path, std::fstream::in | std::fstream::out | std::fstream::app);
				ofs << "	hello world" << "\n";
			ofs.close();
		}

		void perfMeasure::printNwMetrics(networkMetrics nm){
			
			float art = 0;
			float afd = 0;
			float apl = 0;
			if (nm.nInData != 0)
			{
				art = nm.responseTime/nm.nInData ;
				afd = nm.fwdLatencyTag/nm.nInData ;
				apl = nm.processLat/nm.nInData ;
			}
			
		
			ofs.open (path, std::fstream::in | std::fstream::out | std::fstream::app);
				ofs	<< "/n						Network_Metrics\n"
					<< 							fixed
					<< "    		Total_Exp_Resp_Time = " << nm.responseTime/1000 <<" mS\n"
					<< "       	   Per_Packet_Resp_Time = " << art/1000 <<" mS\n"
					<< "	      	  Total_Exp_Fwd_Lat = " << nm.fwdLatencyTag/1000 <<" mS\n"
					<< "    		 Per_Packet_Fwd_Lat = " << afd/1000 <<" mS\n"
					<< "    	Total_ProcessLat_OnPath = " << nm.processLat/1000 <<" mS\n"
					<< "   Per_Packet_ProcessLat_OnPath = " << apl/1000 << " mS\n"
					<< "   	 	   Total_InData_Packets = " << nm.nInData << "\n";
					
			ofs.close();
		
		}
		// std::setprecision(2)
		
		networkMetrics perfMeasure::clearNwMetrics(networkMetrics &nm){
			nm.responseTime = 0;
			nm.fwdLatencyTag = 0; 
			nm.nInData = 0;
			nm.processLat = 0;
			ofs.open (path, std::fstream::in | std::fstream::out | std::fstream::app);
				ofs	<< "Network_Metrics Reset\n";
			ofs.close();
			
			return nm;
			
		}
		
		void perfMeasure::printCsMetrics(csMetrics csm){
				ofs.open (path, std::fstream::in | std::fstream::out | std::fstream::app);
				ofs	<< "/n						Device_Metrics\n"
					<< 							fixed
					<< "    				   nCS_Hits = " << csm.nCsHits <<"\n"	
					<< "    				   nCS_Miss = " << csm.nCsMiss <<"\n"
					<< "    				  Hit_Ratio = " << 100*csm.nCsHits/(csm.nCsHits+csm.nCsMiss) <<" %\n"	
					<< "       Total_csLookUp_Miss_Time = " << csm.csTotalMissLat <<" uS\n"
					<< "  Per_Packet_csLookUp_Miss_Time = " << (csm.nCsMiss!=0) ? csm.csTotalMissLat/csm.nCsMiss : 0<<" uS\n"
					<< "       Total_csLookUp_Hit_Time  = " << csm.csTotalHitLat <<" uS\n"
					<< "   Per_Packet_csLookUp_Hit_Time = " << (csm.nCsHits!=) ? csm.csTotalHitLat/csm.nCsHits : 0<<" uS\n";	
				ofs.close();
		}
		
		csMetrics perfMeasure::clearCsMetrics(csMetrics &csm){
			csm.nCsHits  = 0;
			csm.nCsMiss = 0;
			csm.csTotalMissLat= 0;
			csm.csTotalHitLat = 0;
			ofs.open (path, std::fstream::in | std::fstream::out | std::fstream::app);
				ofs	<< "Device_Metrics Reset\n";
			ofs.close();
			return csm;
		}


		
		


}
}
