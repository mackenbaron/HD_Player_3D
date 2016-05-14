/*
********************************************************************************

NOTE - One of the two copyright statements below may be chosen
       that applies for the software.

********************************************************************************

This software module was originally developed by

Heiko Schwarz    (Fraunhofer HHI),
Tobias Hinz      (Fraunhofer HHI),
Karsten Suehring (Fraunhofer HHI)

in the course of development of the ISO/IEC 14496-10:2005 Amd.1 (Scalable Video
Coding) for reference purposes and its performance may not have been optimized.
This software module is an implementation of one or more tools as specified by
the ISO/IEC 14496-10:2005 Amd.1 (Scalable Video Coding).

Those intending to use this software module in products are advised that its
use may infringe existing patents. ISO/IEC have no liability for use of this
software module or modifications thereof.

Assurance that the originally developed software module can be used
(1) in the ISO/IEC 14496-10:2005 Amd.1 (Scalable Video Coding) once the
ISO/IEC 14496-10:2005 Amd.1 (Scalable Video Coding) has been adopted; and
(2) to develop the ISO/IEC 14496-10:2005 Amd.1 (Scalable Video Coding): 

To the extent that Fraunhofer HHI owns patent rights that would be required to
make, use, or sell the originally developed software module or portions thereof
included in the ISO/IEC 14496-10:2005 Amd.1 (Scalable Video Coding) in a
conforming product, Fraunhofer HHI will assure the ISO/IEC that it is willing
to negotiate licenses under reasonable and non-discriminatory terms and
conditions with applicants throughout the world.

Fraunhofer HHI retains full right to modify and use the code for its own
purpose, assign or donate the code to a third party and to inhibit third
parties from using the code for products that do not conform to MPEG-related
ITU Recommendations and/or ISO/IEC International Standards. 

This copyright notice must be included in all copies or derivative works.
Copyright (c) ISO/IEC 2005. 

********************************************************************************

COPYRIGHT AND WARRANTY INFORMATION

Copyright 2005, International Telecommunications Union, Geneva

The Fraunhofer HHI hereby donate this source code to the ITU, with the following
understanding:
    1. Fraunhofer HHI retain the right to do whatever they wish with the
       contributed source code, without limit.
    2. Fraunhofer HHI retain full patent rights (if any exist) in the technical
       content of techniques and algorithms herein.
    3. The ITU shall make this code available to anyone, free of license or
       royalty fees.

DISCLAIMER OF WARRANTY

These software programs are available to the user without any license fee or
royalty on an "as is" basis. The ITU disclaims any and all warranties, whether
express, implied, or statutory, including any implied warranties of
merchantability or of fitness for a particular purpose. In no event shall the
contributor or the ITU be liable for any incidental, punitive, or consequential
damages of any kind whatsoever arising from the use of these programs.

This disclaimer of warranty extends to the user of these programs and user's
customers, employees, agents, transferees, successors, and assigns.

The ITU does not represent or warrant that the programs furnished hereunder are
free of infringement of any third-party patents. Commercial implementations of
ITU-T Recommendations, including shareware, may be subject to royalty fees to
patent holders. Information regarding the ITU-T patent policy is available from 
the ITU Web site at http://www.itu.int.

THIS IS NOT A GRANT OF PATENT RIGHTS - SEE THE ITU-T PATENT POLICY.

********************************************************************************
*/






#if !defined(AFX_PARAMETERSETMNG_H__5F7FDE27_D5CF_4594_A15B_EE376A1650D7__INCLUDED_)
#define AFX_PARAMETERSETMNG_H__5F7FDE27_D5CF_4594_A15B_EE376A1650D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "H264AVCCommonLib/SequenceParameterSet.h"

#include "list"

#if defined( WIN32 )
# pragma warning( disable: 4251 )
#endif


H264AVC_NAMESPACE_BEGIN

class H264AVCCOMMONLIB_API ParameterSetMng
{
protected:
  ParameterSetMng();
  virtual ~ParameterSetMng() {}

public:
  static ErrVal create( ParameterSetMng*& rpcParameterSetMng );
  ErrVal destroy();
  ErrVal init()                                        { return Err::m_nOK; }
  ErrVal uninit();

  ErrVal setParamterSetList( std::list<SequenceParameterSet*>& rcSPSList, std::list<PictureParameterSet*>& rcPPSList) const;
  Bool   isValidSPS( UInt uiSPSId )                    { return m_cSPSBuf.isValidOffset(uiSPSId) && NULL != m_cSPSBuf.get( uiSPSId); }
  ErrVal get( SequenceParameterSet *& rpcSPS, UInt uiSPSId);
  ErrVal store( SequenceParameterSet* pcSPS );
  ErrVal get( PictureParameterSet *& rpcPPS, UInt uiPPSId );
  Bool   isValidPPS( UInt uiPPSId )                    { return m_cPPSBuf.isValidOffset(uiPPSId) && NULL != m_cPPSBuf.get( uiPPSId); }
  ErrVal store( PictureParameterSet* pcPPS );

private:
  ErrVal xDestroyPPS(UInt uiPPSId);
  ErrVal xDestroySPS(UInt uiSPSId);

private:
  StatBuf<SequenceParameterSet*,32>  m_cSPSBuf;
  StatBuf<PictureParameterSet*,256> m_cPPSBuf;
  UInt m_uiActiveSPSId;
  UInt m_uiActivePPSId;
  std::list<SequenceParameterSet*>  m_cSPSList;
  std::list<PictureParameterSet*>   m_cPPSList;
};



H264AVC_NAMESPACE_END


#if defined( WIN32 )
# pragma warning( default: 4251 )
#endif

#endif // !defined(AFX_PARAMETERSETMNG_H__5F7FDE27_D5CF_4594_A15B_EE376A1650D7__INCLUDED_)