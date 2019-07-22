//
// Created by xuqi on 2019-07-17.
//

#ifndef V2XTYPE_H
#define V2XTYPE_H

#endif //V2XTYPE_H

namespace v2x {

/* DSecond */
typedef long	 DSecond_t;
/* Latitude */
typedef long	 Latitude_t;
/* Longitude */
typedef long	 Longitude_t;
/* Elevation */
typedef long	 Elevation_t;

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

/* TransmissionState */
typedef long	 TransmissionState_t;

/* Speed */
typedef long	 Speed_t;

/* Heading */
typedef long	 Heading_t;

/* VehicleWidth */
typedef long	 VehicleWidth_t;

/* VehicleLength */
typedef long	 VehicleLength_t;

}