// evmone: Fast Ethereum Virtual Machine implementation
// Copyright 2023 The evmone Authors.
// SPDX-License-Identifier: Apache-2.0

#include "../utils/utils.hpp"
#include "evmone_precompiles/bn254.hpp"
#include <gtest/gtest.h>

using namespace evmmax::bn254;
using namespace intx;


TEST(evmmax, bn254_pairing)
{
    //    std::vector<Point> vG1 = {
    //        {
    //            0x3034dd2920f673e204fee2811c678745fc819b55d3e9d294e45c9b03a76aef41_u256,
    //            0x1c76476f4def4bb94541d57ebba1193381ffa7aa76ada664dd31c16024c43f59_u256,
    //        },
    //        {
    //            0x2032c61a830e3c17286de9462bf242fca2883585b93870a73853face6a6bf411_u256,
    //            0x111e129f1cf1097710d41c4ac70fcdfa5ba2023c6ff1cbeac322de49d1b6df7c_u256,
    //        },
    //    };
    //
    //    std::vector<std::array<uint256, 4>> vG2 = {
    //        {
    //            0x04bf11ca01483bfa8b34b43561848d28905960114c8ac04049af4b6315a41678_u256,
    //            0x209dd15ebff5d46c4bd888e51a93cf99a7329636c63514396b4a452003a35bf7_u256,
    //            0x120a2a4cf30c1bf9845f20c6fe39e07ea2cce61f0c9bb048165fe5e4de877550_u256,
    //            0x2bb8324af6cfc93537a2ad1a445cfd0ca2a71acd7ac41fadbf933c2a51be344d_u256,
    //        },
    //        {
    //            0x1800deef121f1e76426a00665e5c4479674322d4f75edadd46debd5cd992f6ed_u256,
    //            0x198e9393920d483a7260bfb731fb5d25f1aa493335a9e71297e485b7aef312c2_u256,
    //            0x12c85ea5db8c6deb4aab71808dcb408fe3d1e7690c43d37b4ce6cc0166fa7daa_u256,
    //            0x090689d0585ff075ec9e99ad690c3395bc4b313370b38ef355acdadcd122975b_u256,
    //        },
    //    };
    {
        // vG1[0] == -vG1[1]
        std::vector<Point> vG1 = {
            {
                0x1c76476f4def4bb94541d57ebba1193381ffa7aa76ada664dd31c16024c43f59_u256,
                0x3034dd2920f673e204fee2811c678745fc819b55d3e9d294e45c9b03a76aef41_u256,
            },
            {
                0x1c76476f4def4bb94541d57ebba1193381ffa7aa76ada664dd31c16024c43f59_u256,
                0x2f7149c03b2c47b35163356519d1179affcf3b9487f7f857c3f11331120e06_u256,
            },
        };

        std::vector<std::array<uint256, 4>> vG2 = {
            {
                0x04bf11ca01483bfa8b34b43561848d28905960114c8ac04049af4b6315a41678_u256,
                0x209dd15ebff5d46c4bd888e51a93cf99a7329636c63514396b4a452003a35bf7_u256,
                0x120a2a4cf30c1bf9845f20c6fe39e07ea2cce61f0c9bb048165fe5e4de877550_u256,
                0x2bb8324af6cfc93537a2ad1a445cfd0ca2a71acd7ac41fadbf933c2a51be344d_u256,
            },
            {
                0x04bf11ca01483bfa8b34b43561848d28905960114c8ac04049af4b6315a41678_u256,
                0x209dd15ebff5d46c4bd888e51a93cf99a7329636c63514396b4a452003a35bf7_u256,
                0x120a2a4cf30c1bf9845f20c6fe39e07ea2cce61f0c9bb048165fe5e4de877550_u256,
                0x2bb8324af6cfc93537a2ad1a445cfd0ca2a71acd7ac41fadbf933c2a51be344d_u256,
            },
        };

        EXPECT_EQ(pairing(vG2, vG1), true);
    }

    {
        // vG2[0] == -vG2[1]
        std::vector<Point> vG1 = {
            {
                0x1c76476f4def4bb94541d57ebba1193381ffa7aa76ada664dd31c16024c43f59_u256,
                0x3034dd2920f673e204fee2811c678745fc819b55d3e9d294e45c9b03a76aef41_u256,
            },
            {
                0x1c76476f4def4bb94541d57ebba1193381ffa7aa76ada664dd31c16024c43f59_u256,
                0x3034dd2920f673e204fee2811c678745fc819b55d3e9d294e45c9b03a76aef41_u256,
            },
        };

        std::vector<std::array<uint256, 4>> vG2 = {
            {
                0x04bf11ca01483bfa8b34b43561848d28905960114c8ac04049af4b6315a41678_u256,
                0x209dd15ebff5d46c4bd888e51a93cf99a7329636c63514396b4a452003a35bf7_u256,
                0x120a2a4cf30c1bf9845f20c6fe39e07ea2cce61f0c9bb048165fe5e4de877550_u256,
                0x2bb8324af6cfc93537a2ad1a445cfd0ca2a71acd7ac41fadbf933c2a51be344d_u256,
            },
            {
                0x04bf11ca01483bfa8b34b43561848d28905960114c8ac04049af4b6315a41678_u256,
                0x209dd15ebff5d46c4bd888e51a93cf99a7329636c63514396b4a452003a35bf7_u256,
                0x1e5a2425ee25843033f124ef834777def4b484725bd61a4525c0a631f9f587f7_u256,
                0x4ac1c27ea61d6f480ad989c3d245b50f4da4fc3edadaadf7c8d4fec86bec8fa_u256,
            },
        };

        EXPECT_EQ(pairing(vG2, vG1), true);
    }

    {
        // vG1[0] = vG1[0] * 17
        std::vector<Point> vG1 = {
            {
                0x22980b2e458ec77e258b19ca3a7b46181f63c6536307acae03eea236f6919eeb_u256,
                0x4eab993e2ba2cca2b08c216645e3fbcf80ae67515b2c49806c17b90c9d3cad3_u256,
            },
            {
                0x1c76476f4def4bb94541d57ebba1193381ffa7aa76ada664dd31c16024c43f59_u256,
                0x3034dd2920f673e204fee2811c678745fc819b55d3e9d294e45c9b03a76aef41_u256,
            },
        };

        // vG2[1] = -vG2[1] * 16
        std::vector<std::array<uint256, 4>> vG2 = {
            {
                0x04bf11ca01483bfa8b34b43561848d28905960114c8ac04049af4b6315a41678_u256,
                0x209dd15ebff5d46c4bd888e51a93cf99a7329636c63514396b4a452003a35bf7_u256,
                0x120a2a4cf30c1bf9845f20c6fe39e07ea2cce61f0c9bb048165fe5e4de877550_u256,
                0x2bb8324af6cfc93537a2ad1a445cfd0ca2a71acd7ac41fadbf933c2a51be344d_u256,
            },
            {
                0x14191bd65f51663a1d4ad71d8480c3c3260d598aab6ed95681f773abade7fd7a_u256,
                0x299c79589dfb51fd6925fce3a7fc15c441fdafaa24f0d09b7c443befdddde4e5_u256,
                0x1d710ac19a995c6395f33be7f3dcd75e0632a006d196da6b4c9ba78708b6bb78_u256,
                0xcae1001513ae5ddf742aa6dc2f52457d9b14e17765dd74fc098ad06045d434e_u256,
            },
        };

        EXPECT_EQ(pairing(vG2, vG1), false);
    }

    {
        // vG1[0] = vG1[0] * 17
        std::vector<Point> vG1 = {
            {
                0x22980b2e458ec77e258b19ca3a7b46181f63c6536307acae03eea236f6919eeb_u256,
                0x4eab993e2ba2cca2b08c216645e3fbcf80ae67515b2c49806c17b90c9d3cad3_u256,
            },
            {
                0x1c76476f4def4bb94541d57ebba1193381ffa7aa76ada664dd31c16024c43f59_u256,
                0x3034dd2920f673e204fee2811c678745fc819b55d3e9d294e45c9b03a76aef41_u256,
            },
        };

        // vG2[1] = -vG2[1] * 17
        std::vector<std::array<uint256, 4>> vG2 = {
            {
                0x04bf11ca01483bfa8b34b43561848d28905960114c8ac04049af4b6315a41678_u256,
                0x209dd15ebff5d46c4bd888e51a93cf99a7329636c63514396b4a452003a35bf7_u256,
                0x120a2a4cf30c1bf9845f20c6fe39e07ea2cce61f0c9bb048165fe5e4de877550_u256,
                0x2bb8324af6cfc93537a2ad1a445cfd0ca2a71acd7ac41fadbf933c2a51be344d_u256,
            },
            {
                0x11eeb08db4fe0df9d7617f11f5f8f488d643510f825f3730ffb038c84c9260fd_u256,
                0x12bf46039aa40a61762bf97b1bb028cebc6d42e46bbbe67f715eda54808b74c4_u256,
                0x42b65e62de1fd24534db81fd72e7ee832637948c1c466ccb08171e503f23e72_u256,
                0x197a5efb333448885788690df5af2211c1697dd8b7b1f8845b4e30a909d2b0f5_u256,
            },
        };

        EXPECT_EQ(pairing(vG2, vG1), true);
    }
}
