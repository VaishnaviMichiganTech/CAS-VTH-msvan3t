/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2011 Centre Tecnologic de Telecomunicacions de Catalunya (CTTC)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Jaume Nin <jaume.nin@cttc.cat>
 */

#ifndef CV2X_EPC_TEST_GTPU_H
#define CV2X_EPC_TEST_GTPU_H

#include "ns3/cv2x_epc-gtpu-header.h"

#include "ns3/test.h"


using namespace ns3;


/**
 * \ingroup lte
 * \defgroup lte-test lte module tests
 */


/**
 * \ingroup lte-test
 * \ingroup tests
 *
 * \brief Test suite for testing GPRS tunnelling protocol header coding and decoding.
 */
class cv2x_EpsGtpuTestSuite : public TestSuite
{
public:
  cv2x_EpsGtpuTestSuite ();
};

/**
 * Test 1.Check header coding and decoding
 */
class cv2x_EpsGtpuHeaderTestCase : public TestCase
{
public:
  cv2x_EpsGtpuHeaderTestCase ();
  virtual ~cv2x_EpsGtpuHeaderTestCase ();

private:
  virtual void DoRun (void);
};


#endif /* CV2X_EPC_TEST_GTPU_H */
