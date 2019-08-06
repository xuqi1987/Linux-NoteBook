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
}
#endif //V2XTYPE_H