//
// Created by xuqi on 2019-07-17.
//

#ifndef V2XTYPE_H
#define V2XTYPE_H
#include <string>


namespace v2x {

#define	A_SET_OF(type)					\
	struct {					\
		type **array;				\
		int count;	/* Meaningful size */	\
		int size;	/* Allocated size */	\
		void (*free)(type *);			\
	}

#define	A_SEQUENCE_OF(type)	A_SET_OF(type)

/* Dependencies */
typedef enum PositionConfidence {
    PositionConfidence_unavailable	= 0,
    PositionConfidence_a500m	= 1,
    PositionConfidence_a200m	= 2,
    PositionConfidence_a100m	= 3,
    PositionConfidence_a50m	= 4,
    PositionConfidence_a20m	= 5,
    PositionConfidence_a10m	= 6,
    PositionConfidence_a5m	= 7,
    PositionConfidence_a2m	= 8,
    PositionConfidence_a1m	= 9,
    PositionConfidence_a50cm	= 10,
    PositionConfidence_a20cm	= 11,
    PositionConfidence_a10cm	= 12,
    PositionConfidence_a5cm	= 13,
    PositionConfidence_a2cm	= 14,
    PositionConfidence_a1cm	= 15
} e_PositionConfidence;

/* Dependencies */
typedef enum TransmissionState {
    TransmissionState_neutral	= 0,
    TransmissionState_park	= 1,
    TransmissionState_forwardGears	= 2,
    TransmissionState_reverseGears	= 3,
    TransmissionState_reserved1	= 4,
    TransmissionState_reserved2	= 5,
    TransmissionState_reserved3	= 6,
    TransmissionState_unavailable	= 7
} e_TransmissionState;

/* Dependencies */
typedef enum ElevationConfidence {
    ElevationConfidence_unavailable	= 0,
    ElevationConfidence_elev_500_00	= 1,
    ElevationConfidence_elev_200_00	= 2,
    ElevationConfidence_elev_100_00	= 3,
    ElevationConfidence_elev_050_00	= 4,
    ElevationConfidence_elev_020_00	= 5,
    ElevationConfidence_elev_010_00	= 6,
    ElevationConfidence_elev_005_00	= 7,
    ElevationConfidence_elev_002_00	= 8,
    ElevationConfidence_elev_001_00	= 9,
    ElevationConfidence_elev_000_50	= 10,
    ElevationConfidence_elev_000_20	= 11,
    ElevationConfidence_elev_000_10	= 12,
    ElevationConfidence_elev_000_05	= 13,
    ElevationConfidence_elev_000_02	= 14,
    ElevationConfidence_elev_000_01	= 15
} e_ElevationConfidence;

/* Dependencies */
typedef enum BrakePedalStatus {
    BrakePedalStatus_unavailable	= 0,
    BrakePedalStatus_off	= 1,
    BrakePedalStatus_on	= 2
} e_BrakePedalStatus;


/* Dependencies */
typedef enum BrakeAppliedStatus {
    BrakeAppliedStatus_unavailable	= 0,
    BrakeAppliedStatus_leftFront	= 1,
    BrakeAppliedStatus_leftRear	= 2,
    BrakeAppliedStatus_rightFront	= 3,
    BrakeAppliedStatus_rightRear	= 4
} e_BrakeAppliedStatus;

/* Dependencies */
typedef enum TractionControlStatus {
    TractionControlStatus_unavailable	= 0,
    TractionControlStatus_off	= 1,
    TractionControlStatus_on	= 2,
    TractionControlStatus_engaged	= 3
} e_TractionControlStatus;

/* Dependencies */
typedef enum AntiLockBrakeStatus {
    AntiLockBrakeStatus_unavailable	= 0,
    AntiLockBrakeStatus_off	= 1,
    AntiLockBrakeStatus_on	= 2,
    AntiLockBrakeStatus_engaged	= 3
} e_AntiLockBrakeStatus;

/* Dependencies */
typedef enum StabilityControlStatus {
    StabilityControlStatus_unavailable	= 0,
    StabilityControlStatus_off	= 1,
    StabilityControlStatus_on	= 2,
    StabilityControlStatus_engaged	= 3
} e_StabilityControlStatus;

/* Dependencies */
typedef enum BrakeBoostApplied {
    BrakeBoostApplied_unavailable	= 0,
    BrakeBoostApplied_off	= 1,
    BrakeBoostApplied_on	= 2
} e_BrakeBoostApplied;


/* Dependencies */
typedef enum AuxiliaryBrakeStatus {
    AuxiliaryBrakeStatus_unavailable	= 0,
    AuxiliaryBrakeStatus_off	= 1,
    AuxiliaryBrakeStatus_on	= 2,
    AuxiliaryBrakeStatus_reserved	= 3
} e_AuxiliaryBrakeStatus;

/* Dependencies */
typedef enum ParticipantType {
	ParticipantType_unknown	= 0,
	ParticipantType_motor	= 1,
	ParticipantType_non_motor	= 2,
	ParticipantType_pedestrian	= 3,
	ParticipantType_rsu	= 4
	/*
	 * Enumeration is extensible
	 */
} e_ParticipantType;


/* Dependencies */
typedef enum SourceType {
	SourceType_unknown	= 0,
	SourceType_selfinfo	= 1,
	SourceType_v2x	= 2,
	SourceType_video	= 3,
	SourceType_microwaveRadar	= 4,
	SourceType_loop	= 5
	/*
	 * Enumeration is extensible
	 */
} e_SourceType;

/* Dependencies */
typedef enum PositionOffsetLL_PR {
	PositionOffsetLL_PR_NOTHING,	/* No components present */
	PositionOffsetLL_PR_position_LL1,
	PositionOffsetLL_PR_position_LL2,
	PositionOffsetLL_PR_position_LL3,
	PositionOffsetLL_PR_position_LL4,
	PositionOffsetLL_PR_position_LL5,
	PositionOffsetLL_PR_position_LL6,
	PositionOffsetLL_PR_position_LatLon
} PositionOffsetLL_PR;

/* AuxiliaryBrakeStatus */
typedef long	 AuxiliaryBrakeStatus_t;

/* BrakeBoostApplied */
typedef long	 BrakeBoostApplied_t;

/* BrakePedalStatus */
typedef long	 BrakePedalStatus_t;

/* TransmissionState */
typedef long	 TransmissionState_t;

/* PositionConfidence */
typedef long	 PositionConfidence_t;

/* TransmissionState */
typedef long	 TransmissionState_t;

/* MsgCount */
typedef long	 MsgCount_t;
/* DSecond */
typedef long	 DSecond_t;
/* Latitude */
typedef long	 Latitude_t;
/* Longitude */
typedef long	 Longitude_t;
/* Elevation */
typedef long	 Elevation_t;

/* ElevationConfidence */
typedef long	 ElevationConfidence_t;

/* Speed */
typedef long	 Speed_t;

/* Heading */
typedef long	 Heading_t;

/* VehicleWidth */
typedef long	 VehicleWidth_t;

/* VehicleLength */
typedef long	 VehicleLength_t;

/* VehicleHeight */
typedef long	 VehicleHeight_t;

/* SteeringWheelAngle */
typedef long	 SteeringWheelAngle_t;
/* Acceleration */
typedef long	 Acceleration_t;

/* VerticalAcceleration */
typedef long	 VerticalAcceleration_t;

/* TractionControlStatus */
typedef long	 TractionControlStatus_t;

/* YawRate */
typedef long	 YawRate_t;

/* StabilityControlStatus */
typedef long	 StabilityControlStatus_t;
/* AntiLockBrakeStatus */
typedef long	 AntiLockBrakeStatus_t;

/* BasicVehicleClass */
typedef long	 BasicVehicleClass_t;

/* MinuteOfTheYear */
typedef long	 MinuteOfTheYear_t;

/* AlertType */
typedef long	 AlertType_t;

/* Radius */
typedef long	 Radius_t;

/* NodeList */
typedef struct NodeList {
    A_SEQUENCE_OF(struct Node) list;

} NodeList_t;

typedef struct BIT_STRING_s {
    uint8_t *buf;	/* BIT STRING body */
    int size;	/* Size of the above buffer */

    int bits_unused;/* Unused trailing bits in the last octet (0..7) */
} BIT_STRING_t;

typedef struct OCTET_STRING {
    uint8_t *buf;	/* Buffer with consecutive OCTET_STRING bits */
    int size;	/* Size of the buffer */
} OCTET_STRING_t;


typedef OCTET_STRING_t IA5String_t;  /* Implemented via OCTET STRING */

/* DescriptiveName */
typedef IA5String_t	 DescriptiveName_t;

/* Priority */
typedef OCTET_STRING_t	 Priority_t;

/* Position3D */
typedef struct Position3D {
    Latitude_t	 lat;
    Longitude_t	 lon;
    Elevation_t	*elevation	/* OPTIONAL */;

} Position3D_t;

/* AccelerationSet4Way */
typedef struct AccelerationSet4Way {
    Acceleration_t	 Long;
    Acceleration_t	 lat;
    VerticalAcceleration_t	 vert;
    YawRate_t	 yaw;

} AccelerationSet4Way_t;

/* BrakeAppliedStatus */
typedef BIT_STRING_t	 BrakeAppliedStatus_t;

/* PositionConfidenceSet */
typedef struct PositionConfidenceSet {
    PositionConfidence_t	 pos;
    ElevationConfidence_t	*elevation	/* OPTIONAL */;
} PositionConfidenceSet_t;

/* VehicleSize */
typedef struct VehicleSize {
    VehicleWidth_t	 width;
    VehicleLength_t	 length;
    VehicleHeight_t	*height	/* OPTIONAL */;
} VehicleSize_t;

/* VehicleClassification */
typedef struct VehicleClassification {
    BasicVehicleClass_t	 classification;
} VehicleClassification_t;


/* BrakeSystemStatus */
typedef struct BrakeSystemStatus {
    BrakePedalStatus_t	*brakePadel	/* OPTIONAL */;
    BrakeAppliedStatus_t	*wheelBrakes	/* OPTIONAL */;
    TractionControlStatus_t	*traction	/* OPTIONAL */;
    AntiLockBrakeStatus_t	*abs	/* OPTIONAL */;
    StabilityControlStatus_t	*scs	/* OPTIONAL */;
    BrakeBoostApplied_t	*brakeBoost	/* OPTIONAL */;
    AuxiliaryBrakeStatus_t	*auxBrakes	/* OPTIONAL */;
} BrakeSystemStatus_t;

/* IntersectionStateList */
typedef struct IntersectionStateList {
    A_SEQUENCE_OF(struct IntersectionState) list;

} IntersectionStateList_t;

/* PathPointList */
typedef struct PathPointList {
	A_SEQUENCE_OF(struct PositionOffsetLLV) list;

} PathPointList_t;


/* ParticipantList */
typedef struct ParticipantList {
	A_SEQUENCE_OF(struct ParticipantData) list;

} ParticipantList_t;

/* OffsetLL-B14 */
typedef long	 OffsetLL_B14_t;

/* OffsetLL-B12 */
typedef long	 OffsetLL_B12_t;

/* OffsetLL-B16 */
typedef long	 OffsetLL_B16_t;

/* OffsetLL-B18 */
typedef long	 OffsetLL_B18_t;

/* OffsetLL-B22 */
typedef long	 OffsetLL_B22_t;

/* OffsetLL-B24 */
typedef long	 OffsetLL_B24_t;

/* Position-LL-24B */
typedef struct Position_LL_24B {
	OffsetLL_B12_t	 lon;
	OffsetLL_B12_t	 lat;
} Position_LL_24B_t;

/* Position-LL-28B */
typedef struct Position_LL_28B {
	OffsetLL_B14_t	 lon;
	OffsetLL_B14_t	 lat;

} Position_LL_28B_t;

/* Position-LL-32B */
typedef struct Position_LL_32B {
	OffsetLL_B16_t	 lon;
	OffsetLL_B16_t	 lat;
} Position_LL_32B_t;

/* Position-LL-36B */
typedef struct Position_LL_36B {
	OffsetLL_B18_t	 lon;
	OffsetLL_B18_t	 lat;
} Position_LL_36B_t;

/* Position-LL-44B */
typedef struct Position_LL_44B {
	OffsetLL_B22_t	 lon;
	OffsetLL_B22_t	 lat;
} Position_LL_44B_t;


/* Position-LL-48B */
typedef struct Position_LL_48B {
	OffsetLL_B24_t	 lon;
	OffsetLL_B24_t	 lat;
} Position_LL_48B_t;

/* Position-LLmD-64b */
typedef struct Position_LLmD_64b {
	Longitude_t	 lon;
	Latitude_t	 lat;
} Position_LLmD_64b_t;

/* PositionOffsetLL */
typedef struct PositionOffsetLL {
	PositionOffsetLL_PR present;
	union PositionOffsetLL_u {
		Position_LL_24B_t	 position_LL1;
		Position_LL_28B_t	 position_LL2;
		Position_LL_32B_t	 position_LL3;
		Position_LL_36B_t	 position_LL4;
		Position_LL_44B_t	 position_LL5;
		Position_LL_48B_t	 position_LL6;
		Position_LLmD_64b_t	 position_LatLon;
	} choice;

} PositionOffsetLL_t;


/* PositionOffsetLLV */
typedef struct PositionOffsetLLV {
	PositionOffsetLL_t	 offsetLL;
	struct VerticalOffset	*offsetV	/* OPTIONAL */;

} PositionOffsetLLV_t;

/* SourceType */
typedef long	 SourceType_t;

/* ParticipantType */
typedef long	 ParticipantType_t;
/* ParticipantData */
typedef struct ParticipantData {
	ParticipantType_t	 ptcType;
	long	 ptcId;
	SourceType_t	 source;
	OCTET_STRING_t	*id	/* OPTIONAL */;
	OCTET_STRING_t	*plateNo	/* OPTIONAL */;
	DSecond_t	 secMark;
	PositionOffsetLLV_t	 pos;
	PositionConfidenceSet_t	 accuracy;
	TransmissionState_t	*transmission	/* OPTIONAL */;
	Speed_t	 speed;
	Heading_t	 heading;
	SteeringWheelAngle_t	*angle	/* OPTIONAL */;
	struct MotionConfidenceSet	*motionCfd	/* OPTIONAL */;
	struct AccelerationSet4Way	*accelSet	/* OPTIONAL */;
	VehicleSize_t	 size;
	struct VehicleClassification	*vehicleClass	/* OPTIONAL */;
} ParticipantData_t;


//define  error number
typedef enum
{
	REL_SUCCESS = 0,
	REL_FAILED = 1,
	REL_INVALID = 2,
	REL_TIMEOUT = 3,
}ERRNO;
}
#endif //V2XTYPE_H