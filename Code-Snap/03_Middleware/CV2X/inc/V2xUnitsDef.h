//
// Created by root on 19-8-15.
//

#ifndef CV2X_V2XUNITSDEF_H
#define CV2X_V2XUNITSDEF_H

namespace v2x {

/*
 * Detail see DefMotion.asn
 */
#define SPEED(v) 0.02 * v       // Units of  m/s
#define HEADING(v) 0.0125 * v   // Units of degrees

/*
 * Dtail see DefPosition.asn
 */
#define LATITUDE(v) v/100000.0  // Units of degree


}
#endif //CV2X_V2XUNITSDEF_H
