#ifdef NS3_MODULE_COMPILATION 
    error "Do not include ns3 module aggregator headers from other modules these are meant only for end user scripts." 
#endif 
#ifndef NS3_MODULE_LTE
    // Module headers: 
    #include <ns3/emu-epc-helper.h>
    #include <ns3/cc-helper.h>
    #include <ns3/epc-helper.h>
    #include <ns3/lte-global-pathloss-database.h>
    #include <ns3/lte-helper.h>
    #include <ns3/lte-hex-grid-enb-topology-helper.h>
    #include <ns3/lte-stats-calculator.h>
    #include <ns3/mac-stats-calculator.h>
    #include <ns3/no-backhaul-epc-helper.h>
    #include <ns3/phy-rx-stats-calculator.h>
    #include <ns3/phy-stats-calculator.h>
    #include <ns3/phy-tx-stats-calculator.h>
    #include <ns3/point-to-point-epc-helper.h>
    #include <ns3/radio-bearer-stats-calculator.h>
    #include <ns3/radio-bearer-stats-connector.h>
    #include <ns3/radio-environment-map-helper.h>
    #include <ns3/a2-a4-rsrq-handover-algorithm.h>
    #include <ns3/a3-rsrp-handover-algorithm.h>
    #include <ns3/component-carrier-enb.h>
    #include <ns3/component-carrier-ue.h>
    #include <ns3/component-carrier.h>
    #include <ns3/cqa-ff-mac-scheduler.h>
    #include <ns3/epc-enb-application.h>
    #include <ns3/epc-enb-s1-sap.h>
    #include <ns3/epc-gtpc-header.h>
    #include <ns3/epc-gtpu-header.h>
    #include <ns3/epc-mme-application.h>
    #include <ns3/epc-pgw-application.h>
    #include <ns3/epc-s11-sap.h>
    #include <ns3/epc-s1ap-sap.h>
    #include <ns3/epc-sgw-application.h>
    #include <ns3/epc-tft-classifier.h>
    #include <ns3/epc-tft.h>
    #include <ns3/epc-ue-nas.h>
    #include <ns3/epc-x2-header.h>
    #include <ns3/epc-x2-sap.h>
    #include <ns3/epc-x2.h>
    #include <ns3/eps-bearer-tag.h>
    #include <ns3/eps-bearer.h>
    #include <ns3/fdbet-ff-mac-scheduler.h>
    #include <ns3/fdmt-ff-mac-scheduler.h>
    #include <ns3/fdtbfq-ff-mac-scheduler.h>
    #include <ns3/ff-mac-common.h>
    #include <ns3/ff-mac-csched-sap.h>
    #include <ns3/ff-mac-sched-sap.h>
    #include <ns3/ff-mac-scheduler.h>
    #include <ns3/lte-amc.h>
    #include <ns3/lte-anr-sap.h>
    #include <ns3/lte-anr.h>
    #include <ns3/lte-as-sap.h>
    #include <ns3/lte-asn1-header.h>
    #include <ns3/lte-ccm-mac-sap.h>
    #include <ns3/lte-ccm-rrc-sap.h>
    #include <ns3/lte-chunk-processor.h>
    #include <ns3/lte-common.h>
    #include <ns3/lte-control-messages.h>
    #include <ns3/lte-enb-cmac-sap.h>
    #include <ns3/lte-enb-component-carrier-manager.h>
    #include <ns3/lte-enb-cphy-sap.h>
    #include <ns3/lte-enb-mac.h>
    #include <ns3/lte-enb-net-device.h>
    #include <ns3/lte-enb-phy-sap.h>
    #include <ns3/lte-enb-phy.h>
    #include <ns3/lte-enb-rrc.h>
    #include <ns3/lte-ffr-algorithm.h>
    #include <ns3/lte-ffr-distributed-algorithm.h>
    #include <ns3/lte-ffr-enhanced-algorithm.h>
    #include <ns3/lte-ffr-rrc-sap.h>
    #include <ns3/lte-ffr-sap.h>
    #include <ns3/lte-ffr-soft-algorithm.h>
    #include <ns3/lte-fr-hard-algorithm.h>
    #include <ns3/lte-fr-no-op-algorithm.h>
    #include <ns3/lte-fr-soft-algorithm.h>
    #include <ns3/lte-fr-strict-algorithm.h>
    #include <ns3/lte-handover-algorithm.h>
    #include <ns3/lte-handover-management-sap.h>
    #include <ns3/lte-harq-phy.h>
    #include <ns3/lte-interference.h>
    #include <ns3/lte-mac-sap.h>
    #include <ns3/lte-mi-error-model.h>
    #include <ns3/lte-net-device.h>
    #include <ns3/lte-pdcp-header.h>
    #include <ns3/lte-pdcp-sap.h>
    #include <ns3/lte-pdcp-tag.h>
    #include <ns3/lte-pdcp.h>
    #include <ns3/lte-phy-tag.h>
    #include <ns3/lte-phy.h>
    #include <ns3/lte-radio-bearer-info.h>
    #include <ns3/lte-radio-bearer-tag.h>
    #include <ns3/lte-rlc-am-header.h>
    #include <ns3/lte-rlc-am.h>
    #include <ns3/lte-rlc-header.h>
    #include <ns3/lte-rlc-sap.h>
    #include <ns3/lte-rlc-sdu-status-tag.h>
    #include <ns3/lte-rlc-sequence-number.h>
    #include <ns3/lte-rlc-tag.h>
    #include <ns3/lte-rlc-tm.h>
    #include <ns3/lte-rlc-um.h>
    #include <ns3/lte-rlc.h>
    #include <ns3/lte-rrc-header.h>
    #include <ns3/lte-rrc-protocol-ideal.h>
    #include <ns3/lte-rrc-protocol-real.h>
    #include <ns3/lte-rrc-sap.h>
    #include <ns3/lte-spectrum-phy.h>
    #include <ns3/lte-spectrum-signal-parameters.h>
    #include <ns3/lte-spectrum-value-helper.h>
    #include <ns3/lte-ue-ccm-rrc-sap.h>
    #include <ns3/lte-ue-cmac-sap.h>
    #include <ns3/lte-ue-component-carrier-manager.h>
    #include <ns3/lte-ue-cphy-sap.h>
    #include <ns3/lte-ue-mac.h>
    #include <ns3/lte-ue-net-device.h>
    #include <ns3/lte-ue-phy-sap.h>
    #include <ns3/lte-ue-phy.h>
    #include <ns3/lte-ue-power-control.h>
    #include <ns3/lte-ue-rrc.h>
    #include <ns3/lte-vendor-specific-parameters.h>
    #include <ns3/no-op-component-carrier-manager.h>
    #include <ns3/no-op-handover-algorithm.h>
    #include <ns3/pf-ff-mac-scheduler.h>
    #include <ns3/pss-ff-mac-scheduler.h>
    #include <ns3/rem-spectrum-phy.h>
    #include <ns3/rr-ff-mac-scheduler.h>
    #include <ns3/simple-ue-component-carrier-manager.h>
    #include <ns3/tdbet-ff-mac-scheduler.h>
    #include <ns3/tdmt-ff-mac-scheduler.h>
    #include <ns3/tdtbfq-ff-mac-scheduler.h>
    #include <ns3/tta-ff-mac-scheduler.h>
    #include <ns3/lte-sl-pdcp-header.h>
    #include <ns3/lte-sl-tft.h>
    #include <ns3/nr-sl-comm-resource-pool.h>
    #include <ns3/nr-sl-mac-sap.h>
    #include <ns3/nr-sl-pdcp-sap.h>
    #include <ns3/nr-sl-rlc-sap.h>
    #include <ns3/nr-sl-rrc-sap.h>
    #include <ns3/nr-sl-ue-bwpm-rrc-sap.h>
    #include <ns3/nr-sl-ue-cmac-sap.h>
    #include <ns3/nr-sl-ue-cphy-sap.h>
    #include <ns3/nr-sl-ue-rrc.h>
#endif 