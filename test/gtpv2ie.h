/* Information Element type values according to 3GPP TS 29.274 Table 8.1-1 */
#define IE_IMSI                                                  (1)
#define IE_CAUSE                                                 (2)
#define IE_RECOVERY_RESTART_COUNTER                              (3)
#define IE_ACCESS_POINT_NAME                                     (71)
#define IE_AGGREGATE_MAXIMUM_BIT_RATE                            (72)
#define IE_EPS_BEARER_ID                                         (73)
#define IE_IP_ADDRESS                                            (74)
#define IE_MOBILE_EQUIPMENT_IDENTITY                             (75)
#define IE_MSISDN                                                (76)
#define IE_INDICATION                                            (77)
#define IE_PROTOCOL_CONFIGURATION_OPTIONS                        (78)
#define IE_PDN_ADDRESS_ALLOCATION                                (79)
#define IE_BEARER_QUALITY_OF_SERVICE                             (80)
#define IE_FLOW_QUALITY_OF_SERVICE                               (81)
#define IE_RAT_TYPE                                              (82)
#define IE_SERVING_NETWORK                                       (83)
#define IE_EPS_BEARER_LEVEL_TRAFFIC_FLOW_TEMPLATE                (84)
#define IE_TRAFFIC_AGGREGATE_DESCRIPTION                         (85)
#define IE_USER_LOCATION_INFORMATION                             (86)
#define IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER            (87)
#define IE_TMSI                                                  (88)
#define IE_GLOBAL_CN_ID                                          (89)
#define IE_S103_PDN_DATA_FORWARDING_INFO                         (90)
#define IE_S1U_DATA_FORWARDING_INFO                              (91)
#define IE_DELAY_VALUE                                           (92)
#define IE_BEARER_CONTEXT                                        (93)
#define IE_CHARGING_ID                                           (94)
#define IE_CHARGING_CHARACTERISTICS                              (95)
#define IE_TRACE_INFORMATION                                     (96)
#define IE_BEARER_FLAGS                                          (97)
#define IE_PDN_TYPE                                              (99)
#define IE_PROCEDURE_TRANSACTION_ID                              (100)
#define IE_MM_CONTEXT_GSM_KEY_AND_TRIPLETS                       (103)
#define IE_MM_CONTEXT_UMTS_KEY_USED_CIPHER_AND_QUINTUPLETS       (104)
#define IE_MM_CONTEXT_GSM_KEY_USED_CIPHER_AND_QUINTUPLETS        (105)
#define IE_MM_CONTEXT_UMTS_KEY_AND_QUINTUPLETS                   (106)
#define IE_MM_CONTEXT_EPS_SECURITY_CONTEXT_AND_QUADRUPLETS       (107)
#define IE_MM_CONTEXT_UMTS_KEY_QUADRUPLETS_AND_QUINTUPLETS       (108)
#define IE_PDN_CONNECTION                                        (109)
#define IE_PDU_NUMBERS                                           (110)
#define IE_PACKET_TMSI                                           (111)
#define IE_P_TMSI_SIGNATURE                                      (112)
#define IE_HOP_COUNTER                                           (113)
#define IE_UE_TIME_ZONE                                          (114)
#define IE_TRACE_REFERENCE                                       (115)
#define IE_COMPLETE_REQUEST_MESSAGE                              (116)
#define IE_GUTI                                                  (117)
#define IE_FULLY_QUALIFIED_CONTAINER                             (118)
#define IE_FULLY_QUALIFIED_CAUSE                                 (119)
#define IE_PLMN_ID                                               (120)
#define IE_TARGET_IDENTIFICATION                                 (121)
#define IE_PACKET_FLOW_ID                                        (123)
#define IE_RAB_CONTEXT                                           (124)
#define IE_SOURCE_RNC_PDCP_CONTEXT_INFO                          (125)
#define IE_PORT_NUMBER                                           (126)
#define IE_ACCESS_POINT_NAME_RESTRICTION                         (127)
#define IE_SELECTION_MODE                                        (128)
#define IE_SOURCE_IDENTIFICATION                                 (129)
#define IE_CHANGE_REPORTING_ACTION                               (131)
#define IE_FQ_CSID                                               (132)
#define IE_CHANNEL_NEEDED                                        (133)
#define IE_EMLPP_PRIORITY                                        (134)
#define IE_NODE_TYPE                                             (135)
#define IE_FULLY_QUALIFIED_DOMAIN_NAME                           (136)
#define IE_TRANSACTION_IDENTIFIER                                (137)
#define IE_MBMS_SESSION_DURATION                                 (138)
#define IE_MBMS_SERVICE_AREA                                     (139)
#define IE_MBMS_SESSION_IDENTIFIER                               (140)
#define IE_MBMS_FLOW_IDENTIFIER                                  (141)
#define IE_MBMS_IP_MULTICAST_DISTRIBUTION                        (142)
#define IE_MBMS_DISTRIBUTION_ACKNOWLEDGE                         (143)
#define IE_RFSP_INDEX                                            (144)
#define IE_USER_CSG_INFORMATION                                  (145)
#define IE_CSG_REPORTING_ACTION                                  (146)
#define IE_CSG_ID                                                (147)
#define IE_CSG_MEMBERSHIP_INDICATION                             (148)
#define IE_SERVICE_INDICATOR                                     (149)
#define IE_DETACH_TYPE                                           (150)
#define IE_LOCAL_DISTINGUISHED_NAME                              (151)
#define IE_NODE_FEATURES                                         (152)
#define IE_MBMS_TIME_TO_DATA_TRANSFER                            (153)
#define IE_THROTTLING                                            (154)
#define IE_ALLOCATION_RETENTION_PRIORITY                         (155)
#define IE_EPC_TIMER                                             (156)
#define IE_SIGNALLING_PRIORITY_INDICATION                        (157)
#define IE_TMGI                                                  (158)
#define IE_ADDITIONAL_MM_CONTEXT_FOR_SRVCC                       (159)
#define IE_ADDITIONAL_FLAGS_FOR_SRVCC                            (160)
#define IE_MDT_CONFIGURATION                                     (162)
#define IE_ADDITIONAL_PROTOCOL_CONFIGURATION_OPTIONS             (163)
#define IE_ABSOLUTE_TIME_OF_MBMS_DATA_TRANSFER                   (164)
#define IE_H_E_NB_INFORMATION_REPORTING                          (165)
#define IE_IPV4_CONFIGURATION_PARAMETERS                         (166)
#define IE_CHANGE_TO_REPORT_FLAGS                                (167)
#define IE_ACTION_INDICATION                                     (168)
#define IE_TWAN_IDENTIFIER                                       (169)
#define IE_ULI_TIMESTAMP                                         (170)
#define IE_MBMS_FLAGS                                            (171)
#define IE_RAN_NAS_CAUSE                                         (172)
#define IE_CN_OPERATOR_SELECTION_ENTITY                          (173)
#define IE_TRUSTED_WLAN_MODE_INDICATION                          (174)
#define IE_NODE_NUMBER                                           (175)
#define IE_NODE_IDENTIFIER                                       (176)
#define IE_PRESENCE_REPORTING_AREA_ACTION                        (177)
#define IE_PRESENCE_REPORTING_AREA_INFORMATION                   (178)
#define IE_TWAN_IDENTIFIER_TIMESTAMP                             (179)
#define IE_OVERLOAD_CONTROL_INFORMATION                          (180)
#define IE_LOAD_CONTROL_INFORMATION                              (181)
#define IE_METRIC                                                (182)
#define IE_SEQUENCE_NUMBER                                       (183)
#define IE_APN_AND_RELATIVE_CAPACITY                             (184)
#define IE_PAGING_AND_SERVICE_INFORMATION                        (186)
#define IE_INTEGER_NUMBER                                        (187)
#define IE_MILLISECOND_TIME_STAMP                                (188)
#define IE_MONITORING_EVENT_INFORMATION                          (189)
#define IE_ECGI_LIST                                             (190)
#define IE_REMOTE_UE_CONTEXT                                     (191)
#define IE_REMOTE_USER_ID                                        (192)
#define IE_REMOTE_UE_IP_INFORMATION                              (193)
#define IE_CIOT_OPTIMIZATIONS_SUPPORT_INDICATION                 (194)
#define IE_SCEF_PDN_CONNECTION                                   (195)
#define IE_HEADER_COMPRESSION_CONFIGURATION                      (196)
#define IE_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS               (197)
#define IE_SERVING_PLMN_RATE_CONTROL                             (198)
#define IE_COUNTER                                               (199)
#define IE_MAPPED_UE_USAGE_TYPE                                  (200)
#define IE_SECONDARY_RAT_USAGE_DATA_REPORT                       (201)
#define IE_UP_FUNCTION_SELECTION_INDICATION_FLAGS                (202)
#define IE_PRIVATE_EXTENSION                                     (255)
#define IE_WLAN_OFFLOADABILITY_INDICATION                        (1000)
#define IE_MAXIMUM_PACKET_LOSS                                   (1001)
#define NODE_TYPE_E_MME                                            (0)
#define NODE_TYPE_E_SGSN                                           (1)

#define CSG_MEMBERSHIP_INDICATION_E_NON_CSG_MEMBERSHIP             (0)
#define CSG_MEMBERSHIP_INDICATION_E_CSG_MEMBERSHIP                 (1)

#define DAYLIGHT_SAVING_TIME_E_NO_ADJUSTMENT                       (0)
#define DAYLIGHT_SAVING_TIME_E_PLUS_1_HOUR                         (1)
#define DAYLIGHT_SAVING_TIME_E_PLUS_2_HOUR                         (2)

enum container_type_e {
	CONTAINER_TYPE_E_RESERVED = 0,
	CONTAINER_TYPE_E_UTRAN_TRANSPARENT_CONTAINER = 1,
	CONTAINER_TYPE_E_BSS_CONTAINER = 2,
	CONTAINER_TYPE_E_EUTRAN_TRANSPARENT_CONTAINER = 3,
	CONTAINER_TYPE_E_NBIFOM_CONTAINER = 4,
};

enum ran_nas_cause_type_e {
	RAN_NAS_CAUSE_TYPE_E_RADIO_NETWORK_LAYER = 0,
	RAN_NAS_CAUSE_TYPE_E_TRANSPORT_LAYER = 1,
	RAN_NAS_CAUSE_TYPE_E_NAS = 2,
	RAN_NAS_CAUSE_TYPE_E_PROTOCOL = 3,
	RAN_NAS_CAUSE_TYPE_E_MISCELLANEOUS = 4,
};

enum selection_mode_e {
	SELECTION_MODE_E_MS_OR_NETWORK_PROVIDED_APN_SUBSCRIPTION_VERIFIED = 0,
	SELECTION_MODE_E_MS_PROVIDED_APN_SUBSCRIPTION_NOT_VERIFIED = 1,
	SELECTION_MODE_E_NETWORK_PROVIDED_APN_SUBSCRIPTION_NOT_VERIFIED = 2,
	SELECTION_MODE_E_FOR_FUTURE_USE = 3,
};

enum rat_type_e {
	RAT_TYPE_E_RESERVED = 0,
	RAT_TYPE_E_UTRAN = 1,
	RAT_TYPE_E_NR = 10,
	RAT_TYPE_E_GERAN = 2,
	RAT_TYPE_E_WLAN = 3,
	RAT_TYPE_E_GAN = 4,
	RAT_TYPE_E_HSPA_EVOLUTION = 5,
	RAT_TYPE_E_EUTRAN_WB_EUTRAN = 6,
	RAT_TYPE_E_VIRTUAL = 7,
	RAT_TYPE_E_EUTRAN-NB-IOT = 8,
	RAT_TYPE_E_LTE-M = 9,
};

enum pdn_type_e {
	PDN_TYPE_E_IPV4 = 1,
	PDN_TYPE_E_IPV6 = 2,
	PDN_TYPE_E_IPV4V6 = 3,
	PDN_TYPE_E_NON-IP = 4,
};

#define USED_GPRS_PROTECTION_ALGORITHM_E_NO_INTEGRITY_PROTECTION   (0)
#define USED_GPRS_PROTECTION_ALGORITHM_E_GIA4                      (4)
#define USED_GPRS_PROTECTION_ALGORITHM_E_GIA5                      (5)

#define ACCESS_MODE_E_CLOSED_MODE                                  (0)
#define ACCESS_MODE_E_HYBRID_MODE                                  (1)

enum timer_unit_e {
	TIMER_UNIT_E_SECONDS_2 = 0,
	TIMER_UNIT_E_MINUTES_1 = 1,
	TIMER_UNIT_E_MINUTES_10 = 2,
	TIMER_UNIT_E_HOURS_1 = 3,
	TIMER_UNIT_E_HOURS_10 = 4,
	TIMER_UNIT_E_DEACTIVATED = 7,
};

enum used_nas_integrity_protection_e {
	USED_NAS_INTEGRITY_PROTECTION_E_NO_INTEGRITY_PROTECTION = 0,
	USED_NAS_INTEGRITY_PROTECTION_E_128-EIA1 = 1,
	USED_NAS_INTEGRITY_PROTECTION_E_128-EIA2 = 2,
	USED_NAS_INTEGRITY_PROTECTION_E_128-EIA3 = 3,
	USED_NAS_INTEGRITY_PROTECTION_E_EIA4 = 4,
	USED_NAS_INTEGRITY_PROTECTION_E_EIA5 = 5,
	USED_NAS_INTEGRITY_PROTECTION_E_EIA6 = 6,
	USED_NAS_INTEGRITY_PROTECTION_E_EIA7 = 7,
};

enum support_features_e {
	SUPPORT_FEATURES_E_PRN = 1,
	SUPPORT_FEATURES_E_MABR = 2,
	SUPPORT_FEATURES_E_NTSR = 4,
	SUPPORT_FEATURES_E_CIOT = 8,
};

enum cause_type_e {
	CAUSE_TYPE_E_RADIO_NETWORK_LAYER = 0,
	CAUSE_TYPE_E_TRANSPORT_LAYER = 1,
	CAUSE_TYPE_E_NAS = 2,
	CAUSE_TYPE_E_PROTOCOL = 3,
	CAUSE_TYPE_E_MISCELLANEOUS = 4,
};

enum distribution_indication_e {
	DISTRIBUTION_INDICATION_E_NO_RNCS_HAVE_ACCEPTED = 0,
	DISTRIBUTION_INDICATION_E_ALL_RNCS_HAVE_ACCEPTED = 1,
	DISTRIBUTION_INDICATION_E_SOM_RNCS_HAVE_ACCEPTED = 2,
	DISTRIBUTION_INDICATION_E_SPARE = 3,
};

#define CSG_MEMBER_INDICAITON_E_CSG_MEMBERSHIP                     (0)
#define CSG_MEMBER_INDICAITON_E_NON_CSG_MEMBERSHIP                 (1)

enum throttling_unit_e {
	THROTTLING_UNIT_E_SECONDS_2 = 0,
	THROTTLING_UNIT_E_MINUTES_1 = 1,
	THROTTLING_UNIT_E_MINUTES_10 = 2,
	THROTTLING_UNIT_E_HOURS_1 = 3,
	THROTTLING_UNIT_E_HOURS_10 = 4,
	THROTTLING_UNIT_E_DEACTIVATED = 7,
};

enum used_nas_cipher_e {
	USED_NAS_CIPHER_E_NO_CIPHERING = 0,
	USED_NAS_CIPHER_E_128-EEA1 = 1,
	USED_NAS_CIPHER_E_128-EEA2 = 2,
	USED_NAS_CIPHER_E_128-EEA3 = 3,
	USED_NAS_CIPHER_E_EEA4 = 4,
	USED_NAS_CIPHER_E_EEA5 = 5,
	USED_NAS_CIPHER_E_EEA6 = 6,
	USED_NAS_CIPHER_E_EEA7 = 7,
};

enum used_cipher_e {
	USED_CIPHER_E_NO_CIPHERING = 0,
	USED_CIPHER_E_GEA_1 = 1,
	USED_CIPHER_E_GEA_2 = 2,
	USED_CIPHER_E_GEA_3 = 3,
	USED_CIPHER_E_GEA_4 = 4,
	USED_CIPHER_E_GEA_5 = 5,
	USED_CIPHER_E_GEA_6 = 6,
	USED_CIPHER_E_GEA_7 = 7,
};

#define SELECTION_ENTITY_E_UE_SELECTED                             (0)
#define SELECTION_ENTITY_E_NETWORK_SELECTED                        (1)

enum action_e {
	ACTION_E_STOP_REPORTING = 0,
	ACTION_E_START_REPORTING_CGI_SAI = 1,
	ACTION_E_START_REPORTING_RAI = 2,
	ACTION_E_START_REPORTING_TAI = 3,
	ACTION_E_START_REPORTING_ECGI = 4,
	ACTION_E_START_REPORTING_CGI_SAI_AND_RAI = 5,
	ACTION_E_START_REPORTING_TAI_AND_ECGI = 6,
	ACTION_E_START_REPORTING_MACRO_ENODEB_ID_AND_XTENDED_MACRO_ENODEB_ID = 7,
	ACTION_E_START_REPORTING_TAI_MACRO_ENODEB_ID_AND_EXTENDED_MACRO_ENODEB_ID = 8,
};

#define DETACH_TYPE_E_PS                                           (1)
#define DETACH_TYPE_E_COMBINED_PS_CS                               (2)

enum indication_e {
	INDICATION_E_NO_ACTION = 0,
	INDICATION_E_DEACTIVATION = 1,
	INDICATION_E_PAGING = 2,
	INDICATION_E_PAGING_STOP = 3,
};

enum rohc_profiles_e {
	ROHC_PROFILES_E_UDP_IP = 1,
	ROHC_PROFILES_E_UDP_IP2 = 16,
	ROHC_PROFILES_E_ESP_IP = 2,
	ROHC_PROFILES_E_ESP_IP2 = 32,
	ROHC_PROFILES_E_IP = 4,
	ROHC_PROFILES_E_IP2 = 64,
	ROHC_PROFILES_E_TCP_IP = 8,
};

#define COMPLETE_REQUEST_MESSAGE_TYPE_E_COMPLETE_ATTACH_REQUEST    (0)
#define COMPLETE_REQUEST_MESSAGE_TYPE_E_COMPLETE_TAU_REQUEST       (1)

enum protocol_type_e {
	PROTOCOL_TYPE_E_S1AP = 0,
	PROTOCOL_TYPE_E_EMM = 1,
	PROTOCOL_TYPE_E_ESM = 2,
	PROTOCOL_TYPE_E_DIAMETER = 3,
	PROTOCOL_TYPE_E_IKEV2 = 4,
};

#define SOURCE_TYPE_E_CELL_ID                                      (0)
#define SOURCE_TYPE_E_RND_ID                                       (1)
#define SOURCE_TYPE_E_RESERVED                                     (2)

#define SERVICE_INDICATOR_E_CS_CALL                                (1)
#define SERVICE_INDICATOR_E_SMS                                    (2)

#define PRA_ACTION_E_START_REPORTING_CHANGES_OF_UE_PRESENCE_IN_PRA (1)
#define PRA_ACTION_E_STOP_REPORTING_CHANGES_OF_UE_PRESENCE_IN_PRA  (2)
#define PRA_ACTION_E_MODIFY_ELEMENTS_COMPOSING_PRA                 (3)

#define SECONDARY_RAT_TYPE_E_NR                                    (0)
#define SECONDARY_RAT_TYPE_E_UNLICENSED_SPECTRUM                   (1)

enum target_type_e {
	TARGET_TYPE_E_RNC_ID = 0,
	TARGET_TYPE_E_MACRO_ENODEB_ID = 1,
	TARGET_TYPE_E_CELL_IDENTIFIER = 2,
	TARGET_TYPE_E_HOME_ENODEB_ID = 3,
	TARGET_TYPE_E_EXTENDED_MACRO_ENODEB_ID = 4,
	TARGET_TYPE_E_GNODEB_ID = 5,
	TARGET_TYPE_E_MACRO_NG_ENODEB_ID = 6,
	TARGET_TYPE_E_EXTENDED_NG_ENODEB_ID = 7,
};

#define RELAY_IDENTITY_TYPE_E_IPV4_OR_IPV6_ADDRESS                 (0)
#define RELAY_IDENTITY_TYPE_E_FQDN                                 (1)

enum security_mode_e {
	SECURITY_MODE_E_GSM_KEY_AND_TRIPLETS = 0,
	SECURITY_MODE_E_UMTS_KEY_USED_CIPHER_AND_QUINTUPLETS = 1,
	SECURITY_MODE_E_GSM_KEY_USED_CIPHER_AND_QUINTUPLETS = 2,
	SECURITY_MODE_E_UMTS_KEY_AND_QUINTUPLETS = 3,
	SECURITY_MODE_E_EPS_SECURITY_CONTEXT_AND_QUADRUPLETS = 4,
	SECURITY_MODE_E_UMTS_KEY_QUADRUPLETS_AND_QUINTUPLETS = 5,
};

#pragma pack(1)

typedef struct rai_field_t {
	uint8_t mcc_digit_2 :4;
	uint8_t mcc_digit_1 :4;
	uint8_t mnc_digit_3 :4;
	uint8_t mcc_digit_3 :4;
	uint8_t mnc_digit_2 :4;
	uint8_t mnc_digit_1 :4;
	uint16_t location_area_code;
	uint16_t routing_area_code_;
} rai_field;


typedef struct tai_field_t {
	uint8_t mcc_digit_2 :4;
	uint8_t mcc_digit_1 :4;
	uint8_t mnc_digit_3 :4;
	uint8_t mcc_digit_3 :4;
	uint8_t mnc_digit_2 :4;
	uint8_t mnc_digit_1 :4;
	uint16_t tracking_area_code;
} tai_field;


typedef struct target_id_for_type_cell_identifier_t {
	uint8_t cell_identifier[8];
} target_id_for_type_cell_identifier;


typedef struct plmn_id_parameter_t {
	uint8_t mcc_digit_2 :4;
	uint8_t mcc_digit_1 :4;
	uint8_t mnc_digit_1 :4;
	uint8_t mcc_digit_3 :4;
	uint8_t mnc_digit_3 :4;
	uint8_t mnc_digit_2 :4;
} plmn_id_parameter;


typedef struct mm_context_t {
} mm_context;


typedef struct target_id_for_type_gnode_id_t {
	uint8_t mcc_digit_2 :4;
	uint8_t mcc_digit_1 :4;
	uint8_t mnc_digit_3 :4;
	uint8_t mcc_digit_3 :4;
	uint8_t mnc_digit_2_ :4;
	uint8_t mnc_digit_1 :4;
	uint8_t spare :2;
	uint8_t gnodeb_id_length :6;
	uint32_t gnodeb_id;
	uint8_t five_gs_tracking_area_code[3];
} target_id_for_type_gnode_id;


typedef struct authentication_quintuplet_t {
	struct authentication_quintuplet_hdr_t {
		uint8_t rand[16];
		uint8_t xres_length;
	} authentication_quintuplet_hdr;
	char* xres;
	uint8_t ck[16];
	uint8_t ik[16];
	uint8_t autn_length;
	char* autn;
} authentication_quintuplet;


typedef struct authentication_triplet_t {
	uint8_t rand[16];
	uint32_t sres;
	uint8_t kc[8];
} authentication_triplet;


typedef struct lai_field_t {
	uint8_t mcc_digit_2 :4;
	uint8_t mcc_digit_1 :4;
	uint8_t mnc_digit_3 :4;
	uint8_t mcc_digit_3 :4;
	uint8_t mnc_digit_2 :4;
	uint8_t mnc_digit_1 :4;
	uint16_t location_area_code;
} lai_field;


typedef struct extended_macro_enodeb_id_field_t {
	uint8_t mcc_digit_2 :4;
	uint8_t mcc_digit_1 :4;
	uint8_t mnc_digit_3 :4;
	uint8_t mcc_digit_3 :4;
	uint8_t mnc_digit_2_ :4;
	uint8_t mnc_digit_1 :4;
	uint8_t smenb_ :1;
	uint8_t spare :2;
	char*  extended_macro_enodeb_id :21;
} extended_macro_enodeb_id_field;


typedef struct target_id_for_type_extended_macro_enodeb_t {
	uint8_t mcc_digit_2 :4;
	uint8_t mcc_digit_1 :4;
	uint8_t mnc_digit_3 :4;
	uint8_t mcc_digit_3 :4;
	uint8_t mnc_digit_2_ :4;
	uint8_t mnc_digit_1 :4;
	uint8_t smenb_ :1;
	uint8_t spare1 :2;
	char*  extended_macro_enodeb_id :21;
	uint16_t tracking_area_code;
} target_id_for_type_extended_macro_enodeb;


typedef struct cgi_field_t {
	uint8_t mcc_digit_2 :4;
	uint8_t mcc_digit_1 :4;
	uint8_t mnc_digit_3 :4;
	uint8_t mcc_digit_3 :4;
	uint8_t mnc_digit_2 :4;
	uint8_t mnc_digit_1 :4;
	uint16_t location_area_code;
	uint16_t cell_identity;
} cgi_field;


typedef struct authentication_quadruplet_t {
	struct authentication_quadruplet_hdr_t {
		uint8_t xres_length;
		uint8_t rand[16];
	} authentication_quadruplet_hdr;
	char* xres;
	uint8_t autn_length;
	char* autn;
	uint8_t kasme[32];
} authentication_quadruplet;


typedef struct target_id_for_type_macro_ng-enodeb_t {
	uint8_t mcc_digit_2 :4;
	uint8_t mcc_digit_1 :4;
	uint8_t mnc_digit_3 :4;
	uint8_t mcc_digit_3 :4;
	uint8_t mnc_digit_2_ :4;
	uint8_t mnc_digit_1 :4;
	uint8_t spare1 :4;
	uint8_t macro_enodeb_id :4;
	uint16_t macro_ng-enodeb_id;
	uint32_t five_gs_tracking_area_code;
} target_id_for_type_macro_ng-enodeb;


typedef struct macro_enodeb_id_field_t {
	uint8_t mcc_digit_2 :4;
	uint8_t mcc_digit_1 :4;
	uint8_t mnc_digit_3 :4;
	uint8_t mcc_digit_3 :4;
	uint8_t mnc_digit_2_ :4;
	uint8_t mnc_digit_1 :4;
	uint8_t spare :4;
	char*  macro_enodeb_id :20;
} macro_enodeb_id_field;


typedef struct bss_container_t {
	uint8_t spare1 :4;
	uint8_t phx :1;
	uint8_t sapi :1;
	uint8_t rp :1;
	uint8_t pfi :1;
	uint8_t packet_flow_id;
	uint8_t sapi1 :4;
	uint8_t spare2 :1;
	uint8_t radio_priority :3;
	uint8_t xid_parameters_length;
	char* xid_parameters;
} bss_container;


typedef struct sai_field_t {
	uint8_t mcc_digit_2 :4;
	uint8_t mcc_digit_1 :4;
	uint8_t mnc_digit_3 :4;
	uint8_t mcc_digit_3 :4;
	uint8_t mnc_digit_2 :4;
	uint8_t mnc_digit_1 :4;
	uint16_t location_area_code;
	uint16_t service_area_code;
} sai_field;


typedef struct target_id_for_type_home_enodeb_t {
	uint8_t mcc_digit_2 :4;
	uint8_t mcc_digit_1 :4;
	uint8_t mnc_digit_3 :4;
	uint8_t mcc_digit_3 :4;
	uint8_t mnc_digit_2_ :4;
	uint8_t mnc_digit_1 :4;
	uint8_t spare1 :4;
	uint32_t home_enodeb_id :28;
	uint16_t tracking_area_code;
} target_id_for_type_home_enodeb;


typedef struct target_id_for_type_macro_enodeb_t {
	uint8_t mcc_digit_2 :4;
	uint8_t mcc_digit_1 :4;
	uint8_t mnc_digit_3 :4;
	uint8_t mcc_digit_3 :4;
	uint8_t mnc_digit_2_ :4;
	uint8_t mnc_digit_1 :4;
	uint8_t spare1 :4;
	char*  macro_enodeb_id :20;
	uint16_t tracking_area_code;
} target_id_for_type_macro_enodeb;


typedef struct ecgi_field_t {
	uint8_t mcc_digit_2 :4;
	uint8_t mcc_digit_1 :4;
	uint8_t mnc_digit_3 :4;
	uint8_t mcc_digit_3 :4;
	uint8_t mnc_digit_2 :4;
	uint8_t mnc_digit_1 :4;
	uint8_t spare :4;
	uint8_t eci :4;
	uint8_t e_utran_cell_identifier[3];
} ecgi_field;


typedef struct target_id_for_type_extended_macro_ng-enodeb_t {
	uint8_t mcc_digit_2 :4;
	uint8_t mcc_digit_1 :4;
	uint8_t mnc_digit_3 :4;
	uint8_t mcc_digit_3 :4;
	uint8_t mnc_digit_2_ :4;
	uint8_t mnc_digit_1 :4;
	uint8_t smenb_ :1;
	uint8_t spare :2;
	uint8_t extended_macro_enodeb_id :5;
	uint16_t extended_macro_ng-enodeb_id;
	uint8_t five_gs_tracking_area_code[3];
} target_id_for_type_extended_macro_ng-enodeb;


typedef struct target_id_for_type_rnc_id_t {
	struct target_id_for_type_rnc_id_hdr_t {
		uint8_t mcc_digit_2 :4;
		uint8_t mcc_digit_1 :4;
		uint8_t mnc_digit_3 :4;
		uint8_t mcc_digit_3 :4;
		uint8_t mnc_digit_2_ :4;
		uint8_t mnc_digit_1 :4;
		uint16_t lac;
		uint8_t rac;
		uint16_t rnc-id;
	} target_id_for_type_rnc_id_hdr;
	char* extended_rnc-id;
} target_id_for_type_rnc_id;


typedef struct integer_number_ie_t {
	char* integer_number_value;
} integer_number_ie;


typedef struct protocol_configuration_options_ie_t {
	uint8_t protocol_configuration_options;
} protocol_configuration_options_ie;


typedef struct throttling_ie_t {
	uint8_t throttling_delay_unit :3;
	uint8_t throttling_delay_value :5;
	uint8_t throttling_factor;
} throttling_ie;


typedef struct serving_plmn_rate_control_ie_t {
	uint32_t uplink_rate_limit;
	uint32_t downlink_rate_limit;
} serving_plmn_rate_control_ie;


typedef struct channel_needed_ie_t {
	char* channel_needed;
} channel_needed_ie;


typedef struct fully_qualified_domain_name_ie_t {
	char* fqdn;
} fully_qualified_domain_name_ie;


typedef struct ran_nas_cause_ie_t {
	uint8_t protocol_type :4;
	uint8_t cause_type :4;
	char* cause_value;
} ran_nas_cause_ie;


typedef struct service_indicator_ie_t {
	uint8_t service_indicator;
} service_indicator_ie;


typedef struct mdt_configuration_ie_t {
	uint8_t job_type;
	uint32_t list_of_measurements;
	uint8_t reporting_trigger_;
	uint8_t report_interval;
	uint8_t report_amount;
	uint8_t event_threshold_for_rsrp;
	uint8_t event_threshold_for_rsrq;
	uint8_t length_of_area_scope;
	char* area_scope;
	uint8_t spare1 :4;
	uint8_t pli :1;
	uint8_t pmi :1;
	uint8_t mpi :1;
	uint8_t crrmi :1;
	uint8_t collection_period_for_rrm_measurements_lte;
	uint8_t measurement_period_lte;
	uint8_t positioning_method;
	uint8_t number_of_mdt_plmns;
	char* mdt_plmn_list;
} mdt_configuration_ie;


typedef struct recovery_restart_counter_ie_t {
	uint8_t recovery_restart_counter;
} recovery_restart_counter_ie;


typedef struct paging_and_service_information_ie_t {
	uint8_t spare1 :4;
	uint8_t epc_bearer_id :4;
	uint8_t spare2 :7;
	uint8_t ppi :1;
	uint8_t spare3 :2;
	uint8_t paging_policy_indication_value :6;
} paging_and_service_information_ie;


typedef struct guti_ie_t {
	uint8_t mcc_digit_2 :4;
	uint8_t mcc_digit_1 :4;
	uint8_t mnc_digit_3 :4;
	uint8_t mcc_digit_3 :4;
	uint8_t mnc_digit_2 :4;
	uint8_t mnc_digit_1 :4;
	uint16_t mme_group_id;
	uint8_t mme_code;
	char* m-tmsi;
} guti_ie;


typedef struct absolute_time_of_mbms_data_transfer_ie_t {
	uint8_t absolute_time_of_mbms_data_transfer_value_part[8];
} absolute_time_of_mbms_data_transfer_ie;


typedef struct node_identifier_ie_t {
	uint8_t length_of_node_name;
	char* node_name;
	uint8_t length_of_node_realm;
	char* node_realm;
} node_identifier_ie;


typedef struct detach_type_ie_t {
	uint8_t detach_type;
} detach_type_ie;


typedef struct remote_ue_ip_information_ie_t {
	char* remote_ue_ip_information;
} remote_ue_ip_information_ie;


typedef struct bearer_context_ie_t {
	char* bearer_context;
} bearer_context_ie;


typedef struct wlan_offloadability_indication_ie_t {
	uint8_t spare1 :6;
	uint8_t eutran_indication :1;
	uint8_t utran_indication_ :1;
} wlan_offloadability_indication_ie;


typedef struct msisdn_ie_t {
	struct {
		uint8_t number_digit :4;
	} *data*number_digit;
	uint8_t filler :4;
} msisdn_ie;


typedef struct selection_mode_ie_t {
	uint8_t spare1 :6;
	uint8_t selec._mode :2;
} selection_mode_ie;


typedef struct node_number_ie_t {
	uint8_t length_of_node_number;
	char* node_number;
} node_number_ie;


typedef struct mm_context_eps_security_context_and_quadruplets_ie_t {
	struct mm_context_eps_security_context_and_quadruplets_ie_hdr_t {
		uint8_t length_of_extended_access_restriction_data;
		uint8_t security_mode :3;
		uint8_t nhi :1;
		uint8_t drxi :1;
		uint8_t ksiasme :3;
		uint8_t number_of_quintuplets :3;
		uint8_t number_of_quadruplet :3;
		uint8_t uambri :1;
		uint8_t osci :1;
		uint8_t sambri :1;
		uint8_t used_nas_integrity_protection_algorithm :3;
		uint8_t used_nas_cipher :4;
		uint8_t nas_downlink_count[3];
		uint8_t nas_uplink_count[3];
		uint8_t kasme[32];
	} mm_context_eps_security_context_and_quadruplets_ie_hdr;
	char*  *authentication_quadruplet;
	char*  *authentication_quintuplet;
	uint16_t drx_parameter;
	uint8_t nh[32];
	uint8_t spare1 :5;
	uint8_t ncc :3;
	uint32_t uplink_subscribed_ue_ambr;
	uint32_t downlink_subscribed_ue_ambr;
	uint32_t uplink_used_ue_ambr;
	uint32_t downlink_used_ue_ambr;
	uint8_t length_of_ue_network_capability;
	char* ue_network_capability;
	uint8_t length_of_ms_network_capability;
	char* ms_network_capability;
	uint8_t length_of_mobile_equipment_identity;
	char* mobile_equipment_identity;
	uint8_t ecna :1;
	uint8_t nbna :1;
	uint8_t hnna :1;
	uint8_t ena :1;
	uint8_t ina :1;
	uint8_t gana :1;
	uint8_t gena :1;
	uint8_t una :1;
	uint8_t nhi_old :1;
	uint8_t spare2 :1;
	uint8_t old_ksiasme :3;
	uint8_t old_ncc :3;
	uint8_t old_kasme[32];
	uint8_t old_nh[32];
	uint8_t length_of_voice_domain_preference_and_ues_usage_setting;
	char* voice_domain_preference_and_ues_usage_setting;
	uint8_t length_of_ue_radio_capability_for_paging_information;
	char* ue_radio_capability_for_paging_information;
	uint8_t length_of_ue_additional_security_capability;
	char* ue_additional_security_capability;
	uint8_t length_of_ue_nr_security_capability;
	char* ue_nr_security_capability;
} mm_context_eps_security_context_and_quadruplets_ie;


typedef struct mapped_ue_usage_type_ie_t {
	uint16_t mapped_ue_usage_type;
} mapped_ue_usage_type_ie;


typedef struct h_e_nb_information_reporting_ie_t {
	uint8_t spare1 :7;
	uint8_t fti :1;
} h_e_nb_information_reporting_ie;


typedef struct ip_address_ie_t {
	union type_union_u {
		uint32_t ipv4_or_ipv6_address;
		uint8_t ipv4_or_ipv6_address[16];
	} type_union;
} ip_address_ie;


typedef struct delay_value_ie_t {
	uint8_t delay_value;
} delay_value_ie;


typedef struct ue_time_zone_ie_t {
	uint8_t time_zone;
	uint8_t spare1 :6;
	uint8_t daylight_saving_time :2;
} ue_time_zone_ie;


typedef struct rab_context_ie_t {
	uint8_t spare1 :4;
	uint8_t nsapi :4;
	uint16_t dl_gtpu_sequence_number;
	uint16_t ul_gtpu_sequence_number;
	uint16_t dl_pdcp_sequence_number;
	uint16_t ul_pdcp_sequence_number;
} rab_context_ie;


typedef struct presence_reporting_area_information_ie_t {
	uint8_t pra_identifier[3];
	uint8_t spare1 :4;
	uint8_t inapra :2;
	uint8_t apra :1;
	uint8_t opra :1;
	uint8_t ipra :1;
} presence_reporting_area_information_ie;


typedef struct up_function_selection_indication_flags_ie_t {
	uint8_t spare1 :7;
	uint8_t dcnr :1;
} up_function_selection_indication_flags_ie;


typedef struct bearer_flags_ie_t {
	uint8_t spare1 :4;
	uint8_t asi :1;
	uint8_t vind :1;
	uint8_t vb :1;
	uint8_t ppc :1;
} bearer_flags_ie;


typedef struct emlpp_priority_ie_t {
	char* emlpp_priority;
} emlpp_priority_ie;


typedef struct port_number_ie_t {
	uint16_t port_number;
} port_number_ie;


typedef struct trace_information_ie_t {
	uint8_t mcc_digit_2 :4;
	uint8_t mcc_digit_1 :4;
	uint8_t mnc_digit_3 :4;
	uint8_t mcc_digit_3 :4;
	uint8_t mnc_digit_2 :4;
	uint8_t mnc_digit_1 :4;
	uint8_t trace_id[3];
	uint8_t triggering_events[9];
	uint16_t list_of_ne_types;
	uint8_t session_trace_depth;
	uint16_t list_of_interfaces;
	char* ip_address_of_trace_collection_entity_;
} trace_information_ie;


typedef struct fully_qualified_cause_ie_t {
	uint8_t spare1 :4;
	uint8_t cause_type :4;
	char* f-cause_field;
} fully_qualified_cause_ie;


typedef struct monitoring_event_information_ie_t {
	struct monitoring_event_information_ie_hdr_t {
		uint32_t scef_reference_id;
		uint8_t scef_id_length;
		char* scef_id;
	} monitoring_event_information_ie_hdr;
	char* remaining_number_of_reports;
} monitoring_event_information_ie;


typedef struct fully_qualified_container_ie_t {
	uint8_t spare1 :4;
	uint8_t container_type :4;
	uint8_t f_container_field;
} fully_qualified_container_ie;


typedef struct plmn_id_ie_t {
	char* plmn_id;
} plmn_id_ie;


typedef struct access_point_name_ie_t {
	char* access_point_name;
} access_point_name_ie;


typedef struct eps_bearer_id_ie_t {
	uint8_t spare1 :4;
	uint8_t eps_bearer_id :4;
} eps_bearer_id_ie;


typedef struct pdn_type_ie_t {
	uint8_t spare1 :5;
	uint8_t pdn_type :3;
} pdn_type_ie;


typedef struct trace_reference_ie_t {
	uint8_t mcc_digit_2 :4;
	uint8_t mcc_digit_1 :4;
	uint8_t mnc_digit_3 :4;
	uint8_t mcc_digit_3 :4;
	uint8_t mnc_digit_2 :4;
	uint8_t mnc_digit_1 :4;
	uint8_t trace_id[3];
} trace_reference_ie;


typedef struct csg_membership_indication_ie_t {
	uint8_t spare1 :7;
	uint8_t cmi :1;
} csg_membership_indication_ie;


typedef struct secondary_rat_usage_data_report_ie_t {
	uint8_t spare1 :6;
	uint8_t irsgw :1;
	uint8_t irpgw :1;
	uint8_t secondary_rat_type;
	uint8_t spare2 :4;
	uint8_t eps_bearer_id :4;
	uint32_t start_timestamp;
	uint32_t end_timestamp;
	uint8_t usage_data_dl[8];
	uint8_t usage_data_ul[8];
} secondary_rat_usage_data_report_ie;


typedef struct serving_network_ie_t {
	uint8_t mcc_digit_2 :4;
	uint8_t mcc_digit_1 :4;
	uint8_t mnc_digit_3 :4;
	uint8_t mcc_digit_3 :4;
	uint8_t mnc_digit_2 :4;
	uint8_t mnc_digit_1 :4;
} serving_network_ie;


typedef struct extended_protocol_configuration_options_ie_t {
	char* extended_protocol_configuration_options;
} extended_protocol_configuration_options_ie;


typedef struct mbms_ip_multicast_distribution_ie_t {
	uint32_t common_tunnel_endpoint_identifier;
	uint8_t address_type :2;
	uint8_t address_length :6;
	union type_union_u {
		uint32_t ip_multicast_distribution_address;
		uint8_t ip_multicast_distribution_address[16];
	} type_union;
	uint8_t address_type1 :2;
	uint8_t address_length1 :6;
	union type_union_u {
		uint32_t ip_multicast_source_address;
		uint8_t ip_multicast_source_address[16];
	} type_union;
	uint8_t mbms_hc_indicator;
} mbms_ip_multicast_distribution_ie;


typedef struct flow_quality_of_service_ie_t {
	uint8_t label_qci;
	uint8_t maximum_bit_rate_for_uplink[5];
	uint8_t maximum_bit_rate_for_downlink[5];
	uint8_t guaranteed_bit_rate_for_uplink[5];
	uint8_t guaranteed_bit_rate_for_downlink[5];
} flow_quality_of_service_ie;


typedef struct trusted_wlan_mode_indication_ie_t {
	uint8_t spare1 :6;
	uint8_t mcm :2;
	uint8_t scm :1;
} trusted_wlan_mode_indication_ie;


typedef struct indication_ie_t {
	uint8_t daf :1;
	uint8_t dtf :1;
	uint8_t hi :1;
	uint8_t dfi :1;
	uint8_t oi :1;
	uint8_t isrsi :1;
	uint8_t israi :1;
	uint8_t sgwci :1;
	uint8_t sqci :1;
	uint8_t uimsi :1;
	uint8_t cfsi :1;
	uint8_t crsi :1;
	uint8_t p :1;
	uint8_t pt :1;
	uint8_t si :1;
	uint8_t msv :1;
	uint8_t retloc :1;
	uint8_t pbic :1;
	uint8_t srni :1;
	uint8_t s6af :1;
	uint8_t s4af :1;
	uint8_t mbmdt :1;
	uint8_t israu :1;
	uint8_t ccrsi :1;
	uint8_t cprai :1;
	uint8_t arrl :1;
	uint8_t ppof :1;
	uint8_t ppon_ppei :1;
	uint8_t ppsi :1;
	uint8_t csfbi :1;
	uint8_t clii :1;
	uint8_t cpsr :1;
	uint8_t nsi :1;
	uint8_t uasi :1;
	uint8_t dtci :1;
	uint8_t bdwi :1;
	uint8_t psci :1;
	uint8_t pcri :1;
	uint8_t aosi :1;
	uint8_t aopi :1;
	uint8_t roaai :1;
	uint8_t epcosi :1;
	uint8_t cpopci :1;
	uint8_t pmtsmi :1;
	uint8_t s11tf :1;
	uint8_t pnsi :1;
	uint8_t unaccsi :1;
	uint8_t wpmsi :1;
	uint8_t spare1 :1;
	uint8_t spare2 :1;
	uint8_t spare3 :1;
	uint8_t eevrsi :1;
	uint8_t ltemui :1;
	uint8_t ltempi :1;
	uint8_t enbcrsi :1;
	uint8_t tspcmi :1;
} indication_ie;


typedef struct cause_ie_t {
	uint8_t cause_value;
	uint8_t spare1 :5;
	uint8_t pce :1;
	uint8_t bce :1;
	uint8_t cs :1;
	uint8_t type_of_the_offending_ie;
	uint16_t length_of_the_offending_ie;
	uint8_t spare2 :4;
	uint8_t instance :4;
} cause_ie;


typedef struct imsi_ie_t {
	struct {
		uint8_t number_digit :4;
	} *data*number_digit;
	uint8_t digit_pad :4;
} imsi_ie;


typedef struct maximum_packet_loss_ie_t {
	uint8_t spare1 :6;
	uint8_t dl :1;
	uint8_t ul :1;
	uint16_t maximum_packet_loss_rate_ul;
	uint16_t maximum_packet_loss_rate_dl;
} maximum_packet_loss_ie;


typedef struct additional_mm_context_for_srvcc_ie_t {
	uint8_t length_of_the_mobile_station_classmark_2;
	char* mobile_station_classmark_2;
	uint8_t length_of_the_mobile_station_classmark_3;
	char* mobile_station_classmark_3;
	uint8_t length_of_the_supported_codec_list;
	char* supported_codec_list;
} additional_mm_context_for_srvcc_ie;


typedef struct pdn_address_allocation_ie_t {
	uint8_t spare1 :5;
	uint8_t pdn_type :3;
	union type_union_u {
		uint32_t pdn_address_and_prefix;
		uint8_t pdn_address_and_prefix[17];
		uint8_t pdn_address_and_prefix[21];
	} type_union;
} pdn_address_allocation_ie;


typedef struct millisecond_time_stamp_ie_t {
	uint8_t millisecond_time_stamp_value[6];
} millisecond_time_stamp_ie;


typedef struct allocation_retention_priority_ie_t {
	uint8_t spare1 :1;
	uint8_t pci :1;
	uint8_t pl :4;
	uint8_t spare2 :1;
	uint8_t pvi :1;
} allocation_retention_priority_ie;


typedef struct rfsp_index_ie_t {
	uint8_t rfsp_index;
} rfsp_index_ie;


typedef struct eps_bearer_level_traffic_flow_template_ie_t {
	char* eps_bearer_level_traffic_flow_template;
} eps_bearer_level_traffic_flow_template_ie;


typedef struct mm_context_gsm_key_used_cipher_and_quintuplets_ie_t {
	struct mm_context_gsm_key_used_cipher_and_quintuplets_ie_hdr_t {
		uint8_t security_mode :3;
		uint8_t spare1 :1;
		uint8_t drxi :1;
		uint8_t cksn_ksi :3;
		uint8_t number_of_quintuplets :3;
		uint8_t spare2 :3;
		uint8_t uambri :1;
		uint8_t sambri :1;
		uint8_t spare3 :5;
		uint8_t used_cipher :3;
		uint8_t kc[8];
	} mm_context_gsm_key_used_cipher_and_quintuplets_ie_hdr;
	char*  *authentication_quintuplets;
	uint16_t drx_parameter;
	uint32_t uplink_subscribed_ue_ambr;
	uint32_t downlink_subscribed_ue_ambr;
	uint32_t uplink_used_ue_ambr;
	uint32_t downlink_used_ue_ambr;
	uint8_t length_of_ue_network_capability;
	char* ue_network_capability;
	uint8_t length_of_ms_network_capability;
	char* ms_network_capability;
	uint8_t length_of_mobile_equipment_identity;
	char* mobile_equipment_identity;
	uint8_t ecna :1;
	uint8_t nbna :1;
	uint8_t hnna :1;
	uint8_t ena :1;
	uint8_t ina :1;
	uint8_t gana :1;
	uint8_t gena :1;
	uint8_t una :1;
	uint8_t length_of_voice_domain_preference_and_ues_usage_setting;
	char* voice_domain_preference_and_ues_usage_setting;
	uint8_t length_of_higher_bitrates_than_16_mbps_flag;
	uint8_t higher_bitrates_than_16_mbps_flag;
} mm_context_gsm_key_used_cipher_and_quintuplets_ie;


typedef struct fully_qualified_tunnel_endpoint_identifier_ie_t {
	uint32_t ipv4_address;
	uint8_t teid_gre_key;
	uint8_t ipv6_address_[16];
	uint8_t v4 :1;
	uint8_t v6 :1;
	uint8_t interface_type :6;
} fully_qualified_tunnel_endpoint_identifier_ie;


typedef struct local_distinguished_name_ie_t {
	char* ldn;
} local_distinguished_name_ie;


typedef struct procedure_transaction_id_ie_t {
	uint8_t procedure_transaction_id;
} procedure_transaction_id_ie;


typedef struct s1u_data_forwarding_info_ie_t {
	uint8_t spare1 :4;
	uint8_t eps_bearer_id :4;
	uint8_t serving_gw_address_length;
	union type_union_u {
		uint32_t serving_gw_address;
		uint8_t serving_gw_address[16];
	} type_union;
	uint32_t serving_gw_s1u_teid;
} s1u_data_forwarding_info_ie;


typedef struct presence_reporting_area_action_ie_t {
	struct presence_reporting_area_action_ie_hdr_t {
		uint8_t spare1 :4;
		uint8_t inapra :1;
		uint8_t action :3;
		uint8_t presence_reporting_area_identifier[3];
		uint8_t number_of_tai :4;
		uint8_t number_of_rai :4;
		uint8_t spare2 :2;
		uint8_t number_of_macro_enodeb :6;
		uint8_t spare3 :2;
		uint8_t number_of_home_enodeb :6;
		uint8_t spare4 :2;
		uint8_t number_of_ecgi :6;
		uint8_t spare5 :2;
		uint8_t number_of_sai :6;
		uint8_t spare6 :2;
		uint8_t number_of_cgi :6;
	} presence_reporting_area_action_ie_hdr;
	char*  *tais;
	char*  *macro_enb_ids;
	char*  *home_enb_ids;
	char*  *ecgis;
	char*  *rais;
	char*  *sais;
	char*  *cgis;
	uint8_t spare7 :2;
	uint8_t number_of_extended_macro_enodeb :6;
	char*  *extended_macro_enb_ids;
} presence_reporting_area_action_ie;


typedef struct twan_identifier_timestamp_ie_t {
	uint32_t twan_identifier_timestamp_value;
} twan_identifier_timestamp_ie;


typedef struct cn_operator_selection_entity_ie_t {
	uint8_t spare1 :6;
	uint8_t selection_entity :2;
} cn_operator_selection_entity_ie;


typedef struct remote_user_id_ie_t {
	uint8_t spare1 :6;
	uint8_t imeif :1;
	uint8_t msisdnf :1;
	uint8_t length_of_imsi;
	char* imsi;
	uint8_t length_of_msisdn;
	char* msisdn;
	uint8_t length_of_imei;
	char* imei;
} remote_user_id_ie;


typedef struct mm_context_gsm_key_and_triplets_ie_t {
	struct mm_context_gsm_key_and_triplets_ie_hdr_t {
		uint8_t security_mode :3;
		uint8_t spare1 :1;
		uint8_t drxi :1;
		uint8_t cksn :3;
		uint8_t number_of_triplet :3;
		uint8_t spare2 :3;
		uint8_t uambri :1;
		uint8_t sambri :1;
		uint8_t spare3 :5;
		uint8_t used_cipher :3;
		uint8_t kc[8];
	} mm_context_gsm_key_and_triplets_ie_hdr;
	char*  *authentication_triplet;
	uint16_t drx_parameter;
	uint32_t uplink_subscribed_ue_ambr;
	uint32_t downlink_subscribed_ue_ambr;
	uint32_t uplink_used_ue_ambr;
	uint32_t downlink_used_ue_ambr;
	uint8_t length_of_ue_network_capability;
	char* ue_network_capability;
	uint8_t length_of_ms_network_capability;
	char* ms_network_capability;
	uint8_t length_of_mobile_equipment_identity;
	char* mobile_equipment_identity;
	uint8_t ecna :1;
	uint8_t nbna :1;
	uint8_t hnna :1;
	uint8_t ena :1;
	uint8_t ina :1;
	uint8_t gana :1;
	uint8_t gena :1;
	uint8_t una :1;
	uint8_t length_of_voice_domain_preference_and_ue_usage_setting;
	char* voice_domain_preference_and_ue_usage_setting;
} mm_context_gsm_key_and_triplets_ie;


typedef struct mm_context_umts_key_and_quintuplets_ie_t {
	struct mm_context_umts_key_and_quintuplets_ie_hdr_t {
		uint8_t security_mode :3;
		uint8_t spare1 :1;
		uint8_t drxi :1;
		uint8_t ksi :3;
		uint8_t number_of_quintuplets :3;
		uint8_t iovi :1;
		uint8_t gupii :1;
		uint8_t ugipai :1;
		uint8_t uambri :1;
		uint8_t sambri :1;
		uint8_t spare2 :5;
		uint8_t used_gprs_integrity_protection_algorithm :3;
		uint8_t ck[16];
		uint8_t ik[16];
	} mm_context_umts_key_and_quintuplets_ie_hdr;
	char*  *authentication_quintuplet;
	uint16_t drx_parameter;
	uint32_t uplink_subscribed_ue_ambr;
	uint32_t downlink_subscribed_ue_ambr;
	uint32_t uplink_used_ue_ambr;
	uint32_t downlink_used_ue_ambr;
	uint8_t length_of_ue_network_capability;
	char* ue_network_capability;
	uint8_t length_of_ms_network_capability;
	char* ms_network_capability;
	uint8_t length_of_mobile_equipment_identity;
	char* mobile_equipment_identity;
	uint8_t ecna :1;
	uint8_t nbna :1;
	uint8_t hnna :1;
	uint8_t ena :1;
	uint8_t ina :1;
	uint8_t gana :1;
	uint8_t gena :1;
	uint8_t una :1;
	uint8_t length_of_voice_domain_preference_and_ues_usage_setting;
	char* voice_domain_preference_and_ues_usage_setting;
	uint8_t length_of_higher_bitrates_than_16_mbps_flag;
	uint8_t higher_bitrates_than_16_mbps_flag;
	uint8_t iov_updates_counter;
	uint8_t length_of_extended_access_restriction_data;
} mm_context_umts_key_and_quintuplets_ie;


typedef struct private_extension_ie_t {
	uint16_t enterprise_id;
	char* proprietary_value;
} private_extension_ie;


typedef struct csg_reporting_action_ie_t {
	uint8_t spare1 :5;
	uint8_t uciuhc :1;
	uint8_t ucishc :1;
	uint8_t ucicsg :1;
} csg_reporting_action_ie;


typedef struct load_control_information_ie_t {
	char* load_control_information;
} load_control_information_ie;


typedef struct charging_id_ie_t {
	uint32_t charging_id_value;
} charging_id_ie;


typedef struct global_cn_id_ie_t {
	uint8_t mcc_digit_2 :4;
	uint8_t mcc_digit_1 :4;
	uint8_t mnc_digit_3 :4;
	uint8_t mcc_digit_3 :4;
	uint8_t mnc_digit_2 :4;
	uint8_t mnc_digit_1 :4;
	char* cn-id;
} global_cn_id_ie;


typedef struct charging_characteristics_ie_t {
	uint16_t charging_characteristics_value;
} charging_characteristics_ie;


typedef struct mbms_session_duration_ie_t {
	uint8_t mbms_session_duration[3];
} mbms_session_duration_ie;


typedef struct mm_context_umts_key_quadruplets_and_quintuplets_ie_t {
	struct mm_context_umts_key_quadruplets_and_quintuplets_ie_hdr_t {
		uint8_t security_mode :3;
		uint8_t spare1 :1;
		uint8_t drxi :1;
		uint8_t ksiasme :3;
		uint8_t number_of_quintuplets :3;
		uint8_t number_of_quadruplet :3;
		uint8_t uambri :1;
		uint8_t sambri :1;
		uint8_t spare2;
		uint8_t ck[16];
		uint8_t ik[16];
	} mm_context_umts_key_quadruplets_and_quintuplets_ie_hdr;
	char*  *authentication_quadruplet;
	char*  *authentication_quintuplet;
	uint16_t drx_parameter;
	uint32_t uplink_subscribed_ue_ambr;
	uint32_t downlink_subscribed_ue_ambr;
	uint32_t uplink_used_ue_ambr;
	uint32_t downlink_used_ue_ambr;
	uint8_t length_of_ue_network_capability;
	char* ue_network_capability;
	uint8_t length_of_ms_network_capability;
	char* ms_network_capability;
	uint8_t length_of_mobile_equipment_identity;
	char* mobile_equipment_identity;
	uint8_t ecna :1;
	uint8_t nbna :1;
	uint8_t hnna :1;
	uint8_t ena :1;
	uint8_t ina :1;
	uint8_t gana :1;
	uint8_t gena :1;
	uint8_t una :1;
	uint8_t length_of_voice_domain_preference_and_ues_usage_setting;
	char* voice_domain_preference_and_ues_usage_setting;
} mm_context_umts_key_quadruplets_and_quintuplets_ie;


typedef struct mbms_time_to_data_transfer_ie_t {
	uint8_t mbms_time_to_data_transfer_value_part;
} mbms_time_to_data_transfer_ie;


typedef struct remote_ue_context_ie_t {
	char* remote_ue_context;
} remote_ue_context_ie;


typedef struct change_reporting_action_ie_t {
	char* action;
} change_reporting_action_ie;


typedef struct mbms_service_area_ie_t {
	char* mbms_session_duration;
} mbms_service_area_ie;


typedef struct traffic_aggregate_description_ie_t {
	char* traffic_aggregate_description;
} traffic_aggregate_description_ie;


typedef struct p_tmsi_signature_ie_t {
	char* p_tmsi_signature;
} p_tmsi_signature_ie;


typedef struct user_csg_information_ie_t {
	uint8_t mcc_digit_2 :4;
	uint8_t mcc_digit_1 :4;
	uint8_t mnc_digit_3 :4;
	uint8_t mcc_digit_3 :4;
	uint8_t mnc_digit_2 :4;
	uint8_t mnc_digit_1 :4;
	uint8_t spare1 :5;
	uint32_t csg_id :27;
	uint8_t access_mode :2;
	uint8_t spare2 :4;
	uint8_t lcsg :1;
	uint8_t cmi :1;
} user_csg_information_ie;


typedef struct epc_timer_ie_t {
	uint8_t timer_unit :3;
	uint8_t timer_value :5;
} epc_timer_ie;


typedef struct ecgi_list_ie_t {
	struct ecgi_list_ie_hdr_t {
		uint16_t number_of_ecgi_fields;
	} ecgi_list_ie_hdr;
	struct {
		char*  ecgi_list_of_m_ecgi_fields_ :42;
	} *data*ecgi_list_of_m_ecgi_fields_;
} ecgi_list_ie;


typedef struct rat_type_ie_t {
	uint8_t rat_type;
} rat_type_ie;


typedef struct mbms_session_identifier_ie_t {
	uint8_t mbms_session_identifier;
} mbms_session_identifier_ie;


typedef struct scef_pdn_connection_ie_t {
	char* scef_pdn_connection;
} scef_pdn_connection_ie;


typedef struct access_point_name_restriction_ie_t {
	uint8_t restriction_type_value;
} access_point_name_restriction_ie;


typedef struct mbms_flags_ie_t {
	uint8_t spare1 :6;
	uint8_t lmri :1;
	uint8_t msri :1;
} mbms_flags_ie;


typedef struct hop_counter_ie_t {
	char* hop_counter;
} hop_counter_ie;


typedef struct transaction_identifier_ie_t {
	char* transaction_identifier;
} transaction_identifier_ie;


typedef struct csg_id_ie_t {
	uint8_t spare1 :5;
	uint32_t csg_id :27;
} csg_id_ie;


typedef struct s103_pdn_data_forwarding_info_ie_t {
	uint8_t hsgw_address_for_forwarding_length;
	union type_union_u {
		uint32_t hsgw_address_for_forwarding;
		uint8_t hsgw_address_for_forwarding[16];
	} type_union;
	uint32_t gre_key;
	uint8_t eps_bearer_id_number;
} s103_pdn_data_forwarding_info_ie;


typedef struct tmgi_ie_t {
	uint8_t tmgi[6];
} tmgi_ie;


typedef struct mm_context_umts_key_used_cipher_and_quintuplets_ie_t {
	struct mm_context_umts_key_used_cipher_and_quintuplets_ie_hdr_t {
		uint8_t security_mode :3;
		uint8_t spare1 :1;
		uint8_t drxi :1;
		uint8_t cksn_ksi :3;
		uint8_t number_of_quintuplets :3;
		uint8_t iovi :1;
		uint8_t gupii :1;
		uint8_t ugipai :1;
		uint8_t uambri :1;
		uint8_t sambri :1;
		uint8_t spare2 :2;
		uint8_t used_gprs_integrity_protection_algorithm :3;
		uint8_t used_cipher :3;
		uint8_t ck[16];
		uint8_t ik[16];
	} mm_context_umts_key_used_cipher_and_quintuplets_ie_hdr;
	char*  *authentication_quintuplet;
	uint16_t drx_parameter;
	uint32_t uplink_subscribed_ue_ambr;
	uint32_t downlink_subscribed_ue_ambr;
	uint32_t uplink_used_ue_ambr;
	uint32_t downlink_used_ue_ambr;
	uint8_t length_of_ue_network_capability;
	char* ue_network_capability;
	uint8_t length_of_ms_network_capability;
	char* ms_network_capability;
	uint8_t length_of_mobile_equipment_identity;
	char* mobile_equipment_identity;
	uint8_t ecna :1;
	uint8_t nbna :1;
	uint8_t hnna :1;
	uint8_t ena :1;
	uint8_t ina :1;
	uint8_t gana :1;
	uint8_t gena :1;
	uint8_t una :1;
	uint8_t length_of_voice_domain_preference_and_ues_usage_setting;
	char* voice_domain_preference_and_ues_usage_setting;
	uint8_t length_of_higher_bitrates_than_16_mbps_flag;
	uint8_t higher_bitrates_than_16_mbps_flag;
	uint8_t iov_updates_counter;
} mm_context_umts_key_used_cipher_and_quintuplets_ie;


typedef struct uli_timestamp_ie_t {
	uint32_t uli_timestamp_value;
} uli_timestamp_ie;


typedef struct sequence_number_ie_t {
	uint32_t sequence_number;
} sequence_number_ie;


typedef struct apn_and_relative_capacity_ie_t {
	uint8_t relative_capacity;
	uint8_t apn_length;
	char* access_point_name;
} apn_and_relative_capacity_ie;


typedef struct header_compression_configuration_ie_t {
	uint16_t rohc_profiles;
	uint16_t max_cid;
} header_compression_configuration_ie;


typedef struct metric_ie_t {
	uint8_t metric;
} metric_ie;


typedef struct tmsi_ie_t {
	char* tmsi;
} tmsi_ie;


typedef struct node_type_ie_t {
	uint8_t node_type;
} node_type_ie;


typedef struct additional_flags_for_srvcc_ie_t {
	uint8_t spare1 :6;
	uint8_t vf :1;
	uint8_t ics :1;
} additional_flags_for_srvcc_ie;


typedef struct fq_csid_ie_t {
	struct fq_csid_ie_hdr_t {
		uint8_t node_id_type :4;
		uint8_t number_of_csids :4;
		char* node-id;
	} fq_csid_ie_hdr;
	uint16_t *pdn_connection_set_identifier;
} fq_csid_ie;


typedef struct packet_tmsi_ie_t {
	char* packet_tmsi;
} packet_tmsi_ie;


typedef struct mbms_flow_identifier_ie_t {
	uint16_t mbms_flow_identifer;
} mbms_flow_identifier_ie;


typedef struct packet_flow_id_ie_t {
	uint8_t spare1 :4;
	uint8_t ebi :4;
	char* packet_flow_id;
} packet_flow_id_ie;


typedef struct bearer_quality_of_service_ie_t {
	uint8_t spare1 :1;
	uint8_t pci :1;
	uint8_t pl :4;
	uint8_t spare2 :1;
	uint8_t pvi :1;
	uint8_t label_qci;
	uint8_t maximum_bit_rate_for_uplink[5];
	uint8_t maximum_bit_rate_for_downlink[5];
	uint8_t guaranteed_bit_rate_for_uplink[5];
	uint8_t guaranteed_bit_rate_for_downlink[5];
} bearer_quality_of_service_ie;


typedef struct source_rnc_pdcp_context_info_ie_t {
	char* rrc_container;
} source_rnc_pdcp_context_info_ie;


typedef struct pdu_numbers_ie_t {
	uint8_t spare1 :4;
	uint8_t nsapi :4;
	uint16_t dl_gtp-u_sequence_number;
	uint16_t ul_gtp-u_sequence_number;
	uint16_t send_n-pdu_number;
	uint16_t receive_n-pdu_number;
} pdu_numbers_ie;


typedef struct change_to_report_flags_ie_t {
	uint8_t spare1 :6;
	uint8_t tzcr :1;
	uint8_t sncr :1;
} change_to_report_flags_ie;


typedef struct additional_protocol_configuration_options_ie_t {
	char* additional_protocol_configuration_options;
} additional_protocol_configuration_options_ie;


typedef struct aggregate_maximum_bit_rate_ie_t {
	uint32_t apn-ambr_for_uplink;
	uint32_t apn-ambr_for_downlink;
} aggregate_maximum_bit_rate_ie;


typedef struct mbms_distribution_acknowledge_ie_t {
	uint8_t spare1 :6;
	uint8_t distr_ind :2;
} mbms_distribution_acknowledge_ie;


typedef struct twan_identifier_ie_t {
	uint8_t spare1 :3;
	uint8_t laii :1;
	uint8_t opnai :1;
	uint8_t plmni :1;
	uint8_t civai :1;
	uint8_t bssidi :2;
	uint8_t ssid_length;
	char* ssid;
	uint8_t bssid[7];
	uint8_t civic_address_length;
	char* civic_address_information_;
	uint8_t twan_plmn-id_[3];
	uint8_t twan_operator_name_length_;
	char* twan_operator_name_;
	uint8_t relay_identity_type;
	uint8_t relay_identity_length;
	char* relay_identity;
	uint8_t circuit-id_length;
	char* circuit-id;
} twan_identifier_ie;


typedef struct action_indication_ie_t {
	uint8_t spare1 :5;
	uint8_t indication :3;
} action_indication_ie;


typedef struct target_identification_ie_t {
	uint8_t target_type;
	char* target_id;
} target_identification_ie;


typedef struct complete_request_message_ie_t {
	uint8_t complete_request_message_type;
	char* complete_request_message;
} complete_request_message_ie;


typedef struct overload_control_information_ie_t {
	char* overload_control_information;
} overload_control_information_ie;


typedef struct source_identification_ie_t {
	uint8_t target_cell_id[8];
	uint8_t source_type;
	char* source_id;
} source_identification_ie;


typedef struct ipv4_configuration_parameters_ie_t {
	uint8_t subnet_prefix_length;
	uint32_t ipv4_default_router_address;
} ipv4_configuration_parameters_ie;


typedef struct user_location_information_ie_t {
	struct user_location_information_ie_hdr_t {
		uint8_t extended_macro_enodeb_id :1;
		uint8_t macro_enodeb_id :1;
		uint8_t lai :1;
		uint8_t ecgi :1;
		uint8_t tai :1;
		uint8_t rai :1;
		uint8_t sai :1;
		uint8_t cgi :1;
	} user_location_information_ie_hdr;
	cgi_field_t *cgi1;
	sai_field_t *sai1;
	rai_field_t *rai1;
	tai_field_t *tai1;
	ecgi_field_t *ecgi1;
	lai_field_t *lai1;
	macro_enodeb_id_field_t *macro_enodeb_id1;
	extended_macro_enodeb_id_field_t *extended_macro_enodeb_id1;
} user_location_information_ie;


typedef struct ciot_optimizations_support_indication_ie_t {
	uint8_t spare1 :4;
	uint8_t ihcsi :1;
	uint8_t awopdn :1;
	uint8_t scnipdn :1;
	uint8_t sgnipdn :1;
} ciot_optimizations_support_indication_ie;


typedef struct pdn_connection_ie_t {
	char* pdn_connection;
} pdn_connection_ie;


typedef struct counter_ie_t {
	uint32_t timestamp_value;
	uint8_t counter_value;
} counter_ie;


typedef struct mobile_equipment_identity_ie_t {
	struct {
		uint8_t international_mobile_equipment_identity :4;
	} *data*international_mobile_equipment_identity;
	uint8_t sv :4;
} mobile_equipment_identity_ie;


typedef struct signalling_priority_indication_ie_t {
	uint8_t spare1 :7;
	uint8_t lapi :1;
} signalling_priority_indication_ie;


typedef struct node_features_ie_t {
	uint8_t supported-features;
} node_features_ie;


