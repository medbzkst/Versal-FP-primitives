#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <adf.h>
#include "kernels.hpp"
#include <string>
#include "../common/common.h"

using namespace adf;

class simpleGraph : public graph
{
private:
    kernel vmul[PE];

    pktsplit<rows_per_packet> splitter_A[COLS * packet_per_col];
    pktsplit<rows_per_packet> splitter_B[COLS * packet_per_col];
    pktmerge<rows_per_packet> merger[COLS * packet_per_col];

public:
    input_plio StreamIn0_0, StreamIn0_1, StreamIn0_2, StreamIn0_3, StreamIn0_4, StreamIn0_5, StreamIn0_6, StreamIn0_7, StreamIn0_8, StreamIn0_9,
        StreamIn0_10, StreamIn0_11, StreamIn0_12, StreamIn0_13, StreamIn0_14, StreamIn0_15,
        StreamIn0_16, StreamIn0_17, StreamIn0_18, StreamIn0_19,
        StreamIn0_20, StreamIn0_21, StreamIn0_22, StreamIn0_23, StreamIn0_24, StreamIn0_25, StreamIn0_26, StreamIn0_27, StreamIn0_28, StreamIn0_29,
        StreamIn0_30, StreamIn0_31, StreamIn0_32, StreamIn0_33, StreamIn0_34, StreamIn0_35, StreamIn0_36, StreamIn0_37, StreamIn0_38, StreamIn0_39,
        StreamIn0_40, StreamIn0_41, StreamIn0_42, StreamIn0_43, StreamIn0_44, StreamIn0_45, StreamIn0_46, StreamIn0_47, StreamIn0_48, StreamIn0_49,
        StreamIn0_50, StreamIn0_51, StreamIn0_52, StreamIn0_53, StreamIn0_54, StreamIn0_55, StreamIn0_56, StreamIn0_57, StreamIn0_58, StreamIn0_59,
        StreamIn0_60, StreamIn0_61, StreamIn0_62, StreamIn0_63, StreamIn0_64, StreamIn0_65, StreamIn0_66, StreamIn0_67, StreamIn0_68, StreamIn0_69,
        StreamIn0_70, StreamIn0_71, StreamIn0_72, StreamIn0_73, StreamIn0_74, StreamIn0_75, StreamIn0_76, StreamIn0_77, StreamIn0_78, StreamIn0_79,
        StreamIn0_80, StreamIn0_81, StreamIn0_82, StreamIn0_83, StreamIn0_84, StreamIn0_85, StreamIn0_86, StreamIn0_87, StreamIn0_88, StreamIn0_89,
        StreamIn0_90, StreamIn0_91, StreamIn0_92, StreamIn0_93, StreamIn0_94, StreamIn0_95,

        StreamIn1_0, StreamIn1_1, StreamIn1_2, StreamIn1_3, StreamIn1_4, StreamIn1_5, StreamIn1_6, StreamIn1_7, StreamIn1_8, StreamIn1_9,
        StreamIn1_10, StreamIn1_11, StreamIn1_12, StreamIn1_13, StreamIn1_14, StreamIn1_15, StreamIn1_16, StreamIn1_17, StreamIn1_18, StreamIn1_19,
        StreamIn1_20, StreamIn1_21, StreamIn1_22, StreamIn1_23, StreamIn1_24, StreamIn1_25, StreamIn1_26, StreamIn1_27, StreamIn1_28, StreamIn1_29,
        StreamIn1_30, StreamIn1_31, StreamIn1_32, StreamIn1_33, StreamIn1_34, StreamIn1_35, StreamIn1_36, StreamIn1_37, StreamIn1_38, StreamIn1_39,
        StreamIn1_40, StreamIn1_41, StreamIn1_42, StreamIn1_43, StreamIn1_44, StreamIn1_45, StreamIn1_46, StreamIn1_47, StreamIn1_48, StreamIn1_49,
        StreamIn1_50, StreamIn1_51, StreamIn1_52, StreamIn1_53, StreamIn1_54, StreamIn1_55, StreamIn1_56, StreamIn1_57, StreamIn1_58, StreamIn1_59,
        StreamIn1_60, StreamIn1_61, StreamIn1_62, StreamIn1_63, StreamIn1_64, StreamIn1_65, StreamIn1_66, StreamIn1_67, StreamIn1_68, StreamIn1_69,
        StreamIn1_70, StreamIn1_71, StreamIn1_72, StreamIn1_73, StreamIn1_74, StreamIn1_75, StreamIn1_76, StreamIn1_77, StreamIn1_78, StreamIn1_79,
        StreamIn1_80, StreamIn1_81, StreamIn1_82, StreamIn1_83, StreamIn1_84, StreamIn1_85, StreamIn1_86, StreamIn1_87, StreamIn1_88, StreamIn1_89,
        StreamIn1_90, StreamIn1_91, StreamIn1_92, StreamIn1_93, StreamIn1_94, StreamIn1_95;

    output_plio StreamOut0_0, StreamOut0_1, StreamOut0_2, StreamOut0_3, StreamOut0_4, StreamOut0_5, StreamOut0_6, StreamOut0_7, StreamOut0_8, StreamOut0_9,
        StreamOut0_10, StreamOut0_11, StreamOut0_12, StreamOut0_13, StreamOut0_14, StreamOut0_15, StreamOut0_16, StreamOut0_17, StreamOut0_18, StreamOut0_19,
        StreamOut0_20, StreamOut0_21, StreamOut0_22, StreamOut0_23, StreamOut0_24, StreamOut0_25, StreamOut0_26, StreamOut0_27, StreamOut0_28, StreamOut0_29,
        StreamOut0_30, StreamOut0_31, StreamOut0_32, StreamOut0_33, StreamOut0_34, StreamOut0_35, StreamOut0_36, StreamOut0_37, StreamOut0_38, StreamOut0_39,
        StreamOut0_40, StreamOut0_41, StreamOut0_42, StreamOut0_43, StreamOut0_44, StreamOut0_45, StreamOut0_46, StreamOut0_47, StreamOut0_48, StreamOut0_49,
        StreamOut0_50, StreamOut0_51, StreamOut0_52, StreamOut0_53, StreamOut0_54, StreamOut0_55, StreamOut0_56, StreamOut0_57, StreamOut0_58, StreamOut0_59,
        StreamOut0_60, StreamOut0_61, StreamOut0_62, StreamOut0_63, StreamOut0_64, StreamOut0_65, StreamOut0_66, StreamOut0_67, StreamOut0_68, StreamOut0_69,
        StreamOut0_70, StreamOut0_71, StreamOut0_72, StreamOut0_73, StreamOut0_74, StreamOut0_75, StreamOut0_76, StreamOut0_77, StreamOut0_78, StreamOut0_79,
        StreamOut0_80, StreamOut0_81, StreamOut0_82, StreamOut0_83, StreamOut0_84, StreamOut0_85, StreamOut0_86, StreamOut0_87, StreamOut0_88, StreamOut0_89,
        StreamOut0_90, StreamOut0_91, StreamOut0_92, StreamOut0_93, StreamOut0_94, StreamOut0_95;

    simpleGraph()
    {
    input_streams:
    {
        StreamIn0_0 = input_plio::create("StreamIn0_0", adf::plio_32_bits);
        StreamIn0_1 = input_plio::create("StreamIn0_1", adf::plio_32_bits);
        StreamIn0_2 = input_plio::create("StreamIn0_2", adf::plio_32_bits);
        StreamIn0_3 = input_plio::create("StreamIn0_3", adf::plio_32_bits);
        StreamIn0_4 = input_plio::create("StreamIn0_4", adf::plio_32_bits);
        StreamIn0_5 = input_plio::create("StreamIn0_5", adf::plio_32_bits);
        StreamIn0_6 = input_plio::create("StreamIn0_6", adf::plio_32_bits);
        StreamIn0_7 = input_plio::create("StreamIn0_7", adf::plio_32_bits);
        StreamIn0_8 = input_plio::create("StreamIn0_8", adf::plio_32_bits);
        StreamIn0_9 = input_plio::create("StreamIn0_9", adf::plio_32_bits);
        StreamIn0_10 = input_plio::create("StreamIn0_10", adf::plio_32_bits);
        StreamIn0_11 = input_plio::create("StreamIn0_11", adf::plio_32_bits);
        StreamIn0_12 = input_plio::create("StreamIn0_12", adf::plio_32_bits);
        StreamIn0_13 = input_plio::create("StreamIn0_13", adf::plio_32_bits);
        StreamIn0_14 = input_plio::create("StreamIn0_14", adf::plio_32_bits);
        StreamIn0_15 = input_plio::create("StreamIn0_15", adf::plio_32_bits);
        StreamIn0_16 = input_plio::create("StreamIn0_16", adf::plio_32_bits);
        StreamIn0_17 = input_plio::create("StreamIn0_17", adf::plio_32_bits);
        StreamIn0_18 = input_plio::create("StreamIn0_18", adf::plio_32_bits);
        StreamIn0_19 = input_plio::create("StreamIn0_19", adf::plio_32_bits);
        StreamIn0_20 = input_plio::create("StreamIn0_20", adf::plio_32_bits);
        StreamIn0_21 = input_plio::create("StreamIn0_21", adf::plio_32_bits);
        StreamIn0_22 = input_plio::create("StreamIn0_22", adf::plio_32_bits);
        StreamIn0_23 = input_plio::create("StreamIn0_23", adf::plio_32_bits);
        StreamIn0_24 = input_plio::create("StreamIn0_24", adf::plio_32_bits);
        StreamIn0_25 = input_plio::create("StreamIn0_25", adf::plio_32_bits);
        StreamIn0_26 = input_plio::create("StreamIn0_26", adf::plio_32_bits);
        StreamIn0_27 = input_plio::create("StreamIn0_27", adf::plio_32_bits);
        StreamIn0_28 = input_plio::create("StreamIn0_28", adf::plio_32_bits);
        StreamIn0_29 = input_plio::create("StreamIn0_29", adf::plio_32_bits);
        StreamIn0_30 = input_plio::create("StreamIn0_30", adf::plio_32_bits);
        StreamIn0_31 = input_plio::create("StreamIn0_31", adf::plio_32_bits);
        StreamIn0_32 = input_plio::create("StreamIn0_32", adf::plio_32_bits);
        StreamIn0_33 = input_plio::create("StreamIn0_33", adf::plio_32_bits);
        StreamIn0_34 = input_plio::create("StreamIn0_34", adf::plio_32_bits);
        StreamIn0_35 = input_plio::create("StreamIn0_35", adf::plio_32_bits);
        StreamIn0_36 = input_plio::create("StreamIn0_36", adf::plio_32_bits);
        StreamIn0_37 = input_plio::create("StreamIn0_37", adf::plio_32_bits);
        StreamIn0_38 = input_plio::create("StreamIn0_38", adf::plio_32_bits);
        StreamIn0_39 = input_plio::create("StreamIn0_39", adf::plio_32_bits);
        StreamIn0_40 = input_plio::create("StreamIn0_40", adf::plio_32_bits);
        StreamIn0_41 = input_plio::create("StreamIn0_41", adf::plio_32_bits);
        StreamIn0_42 = input_plio::create("StreamIn0_42", adf::plio_32_bits);
        StreamIn0_43 = input_plio::create("StreamIn0_43", adf::plio_32_bits);
        StreamIn0_44 = input_plio::create("StreamIn0_44", adf::plio_32_bits);
        StreamIn0_45 = input_plio::create("StreamIn0_45", adf::plio_32_bits);
        StreamIn0_46 = input_plio::create("StreamIn0_46", adf::plio_32_bits);
        StreamIn0_47 = input_plio::create("StreamIn0_47", adf::plio_32_bits);
        StreamIn0_48 = input_plio::create("StreamIn0_48", adf::plio_32_bits);
        StreamIn0_49 = input_plio::create("StreamIn0_49", adf::plio_32_bits);
        StreamIn0_50 = input_plio::create("StreamIn0_50", adf::plio_32_bits);
        StreamIn0_51 = input_plio::create("StreamIn0_51", adf::plio_32_bits);
        StreamIn0_52 = input_plio::create("StreamIn0_52", adf::plio_32_bits);
        StreamIn0_53 = input_plio::create("StreamIn0_53", adf::plio_32_bits);
        StreamIn0_54 = input_plio::create("StreamIn0_54", adf::plio_32_bits);
        StreamIn0_55 = input_plio::create("StreamIn0_55", adf::plio_32_bits);
        StreamIn0_56 = input_plio::create("StreamIn0_56", adf::plio_32_bits);
        StreamIn0_57 = input_plio::create("StreamIn0_57", adf::plio_32_bits);
        StreamIn0_58 = input_plio::create("StreamIn0_58", adf::plio_32_bits);
        StreamIn0_59 = input_plio::create("StreamIn0_59", adf::plio_32_bits);
        StreamIn0_60 = input_plio::create("StreamIn0_60", adf::plio_32_bits);
        StreamIn0_61 = input_plio::create("StreamIn0_61", adf::plio_32_bits);
        StreamIn0_62 = input_plio::create("StreamIn0_62", adf::plio_32_bits);
        StreamIn0_63 = input_plio::create("StreamIn0_63", adf::plio_32_bits);
        StreamIn0_64 = input_plio::create("StreamIn0_64", adf::plio_32_bits);
        StreamIn0_65 = input_plio::create("StreamIn0_65", adf::plio_32_bits);
        StreamIn0_66 = input_plio::create("StreamIn0_66", adf::plio_32_bits);
        StreamIn0_67 = input_plio::create("StreamIn0_67", adf::plio_32_bits);
        StreamIn0_68 = input_plio::create("StreamIn0_68", adf::plio_32_bits);
        StreamIn0_69 = input_plio::create("StreamIn0_69", adf::plio_32_bits);
        StreamIn0_70 = input_plio::create("StreamIn0_70", adf::plio_32_bits);
        StreamIn0_71 = input_plio::create("StreamIn0_71", adf::plio_32_bits);
        StreamIn0_72 = input_plio::create("StreamIn0_72", adf::plio_32_bits);
        StreamIn0_73 = input_plio::create("StreamIn0_73", adf::plio_32_bits);
        StreamIn0_74 = input_plio::create("StreamIn0_74", adf::plio_32_bits);
        StreamIn0_75 = input_plio::create("StreamIn0_75", adf::plio_32_bits);
        StreamIn0_76 = input_plio::create("StreamIn0_76", adf::plio_32_bits);
        StreamIn0_77 = input_plio::create("StreamIn0_77", adf::plio_32_bits);
        StreamIn0_78 = input_plio::create("StreamIn0_78", adf::plio_32_bits);
        StreamIn0_79 = input_plio::create("StreamIn0_79", adf::plio_32_bits);
        StreamIn0_80 = input_plio::create("StreamIn0_80", adf::plio_32_bits);
        StreamIn0_81 = input_plio::create("StreamIn0_81", adf::plio_32_bits);
        StreamIn0_82 = input_plio::create("StreamIn0_82", adf::plio_32_bits);
        StreamIn0_83 = input_plio::create("StreamIn0_83", adf::plio_32_bits);
        StreamIn0_84 = input_plio::create("StreamIn0_84", adf::plio_32_bits);
        StreamIn0_85 = input_plio::create("StreamIn0_85", adf::plio_32_bits);
        StreamIn0_86 = input_plio::create("StreamIn0_86", adf::plio_32_bits);
        StreamIn0_87 = input_plio::create("StreamIn0_87", adf::plio_32_bits);
        StreamIn0_88 = input_plio::create("StreamIn0_88", adf::plio_32_bits);
        StreamIn0_89 = input_plio::create("StreamIn0_89", adf::plio_32_bits);
        StreamIn0_90 = input_plio::create("StreamIn0_90", adf::plio_32_bits);
        StreamIn0_91 = input_plio::create("StreamIn0_91", adf::plio_32_bits);
        StreamIn0_92 = input_plio::create("StreamIn0_92", adf::plio_32_bits);
        StreamIn0_93 = input_plio::create("StreamIn0_93", adf::plio_32_bits);
        StreamIn0_94 = input_plio::create("StreamIn0_94", adf::plio_32_bits);
        StreamIn0_95 = input_plio::create("StreamIn0_95", adf::plio_32_bits);

        StreamIn1_0 = input_plio::create("StreamIn1_0", adf::plio_32_bits);
        StreamIn1_1 = input_plio::create("StreamIn1_1", adf::plio_32_bits);
        StreamIn1_2 = input_plio::create("StreamIn1_2", adf::plio_32_bits);
        StreamIn1_3 = input_plio::create("StreamIn1_3", adf::plio_32_bits);
        StreamIn1_4 = input_plio::create("StreamIn1_4", adf::plio_32_bits);
        StreamIn1_5 = input_plio::create("StreamIn1_5", adf::plio_32_bits);
        StreamIn1_6 = input_plio::create("StreamIn1_6", adf::plio_32_bits);
        StreamIn1_7 = input_plio::create("StreamIn1_7", adf::plio_32_bits);
        StreamIn1_8 = input_plio::create("StreamIn1_8", adf::plio_32_bits);
        StreamIn1_9 = input_plio::create("StreamIn1_9", adf::plio_32_bits);
        StreamIn1_10 = input_plio::create("StreamIn1_10", adf::plio_32_bits);
        StreamIn1_11 = input_plio::create("StreamIn1_11", adf::plio_32_bits);
        StreamIn1_12 = input_plio::create("StreamIn1_12", adf::plio_32_bits);
        StreamIn1_13 = input_plio::create("StreamIn1_13", adf::plio_32_bits);
        StreamIn1_14 = input_plio::create("StreamIn1_14", adf::plio_32_bits);
        StreamIn1_15 = input_plio::create("StreamIn1_15", adf::plio_32_bits);
        StreamIn1_16 = input_plio::create("StreamIn1_16", adf::plio_32_bits);
        StreamIn1_17 = input_plio::create("StreamIn1_17", adf::plio_32_bits);
        StreamIn1_18 = input_plio::create("StreamIn1_18", adf::plio_32_bits);
        StreamIn1_19 = input_plio::create("StreamIn1_19", adf::plio_32_bits);
        StreamIn1_20 = input_plio::create("StreamIn1_20", adf::plio_32_bits);
        StreamIn1_21 = input_plio::create("StreamIn1_21", adf::plio_32_bits);
        StreamIn1_22 = input_plio::create("StreamIn1_22", adf::plio_32_bits);
        StreamIn1_23 = input_plio::create("StreamIn1_23", adf::plio_32_bits);
        StreamIn1_24 = input_plio::create("StreamIn1_24", adf::plio_32_bits);
        StreamIn1_25 = input_plio::create("StreamIn1_25", adf::plio_32_bits);
        StreamIn1_26 = input_plio::create("StreamIn1_26", adf::plio_32_bits);
        StreamIn1_27 = input_plio::create("StreamIn1_27", adf::plio_32_bits);
        StreamIn1_28 = input_plio::create("StreamIn1_28", adf::plio_32_bits);
        StreamIn1_29 = input_plio::create("StreamIn1_29", adf::plio_32_bits);
        StreamIn1_30 = input_plio::create("StreamIn1_30", adf::plio_32_bits);
        StreamIn1_31 = input_plio::create("StreamIn1_31", adf::plio_32_bits);
        StreamIn1_32 = input_plio::create("StreamIn1_32", adf::plio_32_bits);
        StreamIn1_33 = input_plio::create("StreamIn1_33", adf::plio_32_bits);
        StreamIn1_34 = input_plio::create("StreamIn1_34", adf::plio_32_bits);
        StreamIn1_35 = input_plio::create("StreamIn1_35", adf::plio_32_bits);
        StreamIn1_36 = input_plio::create("StreamIn1_36", adf::plio_32_bits);
        StreamIn1_37 = input_plio::create("StreamIn1_37", adf::plio_32_bits);
        StreamIn1_38 = input_plio::create("StreamIn1_38", adf::plio_32_bits);
        StreamIn1_39 = input_plio::create("StreamIn1_39", adf::plio_32_bits);
        StreamIn1_40 = input_plio::create("StreamIn1_40", adf::plio_32_bits);
        StreamIn1_41 = input_plio::create("StreamIn1_41", adf::plio_32_bits);
        StreamIn1_42 = input_plio::create("StreamIn1_42", adf::plio_32_bits);
        StreamIn1_43 = input_plio::create("StreamIn1_43", adf::plio_32_bits);
        StreamIn1_44 = input_plio::create("StreamIn1_44", adf::plio_32_bits);
        StreamIn1_45 = input_plio::create("StreamIn1_45", adf::plio_32_bits);
        StreamIn1_46 = input_plio::create("StreamIn1_46", adf::plio_32_bits);
        StreamIn1_47 = input_plio::create("StreamIn1_47", adf::plio_32_bits);
        StreamIn1_48 = input_plio::create("StreamIn1_48", adf::plio_32_bits);
        StreamIn1_49 = input_plio::create("StreamIn1_49", adf::plio_32_bits);
        StreamIn1_50 = input_plio::create("StreamIn1_50", adf::plio_32_bits);
        StreamIn1_51 = input_plio::create("StreamIn1_51", adf::plio_32_bits);
        StreamIn1_52 = input_plio::create("StreamIn1_52", adf::plio_32_bits);
        StreamIn1_53 = input_plio::create("StreamIn1_53", adf::plio_32_bits);
        StreamIn1_54 = input_plio::create("StreamIn1_54", adf::plio_32_bits);
        StreamIn1_55 = input_plio::create("StreamIn1_55", adf::plio_32_bits);
        StreamIn1_56 = input_plio::create("StreamIn1_56", adf::plio_32_bits);
        StreamIn1_57 = input_plio::create("StreamIn1_57", adf::plio_32_bits);
        StreamIn1_58 = input_plio::create("StreamIn1_58", adf::plio_32_bits);
        StreamIn1_59 = input_plio::create("StreamIn1_59", adf::plio_32_bits);
        StreamIn1_60 = input_plio::create("StreamIn1_60", adf::plio_32_bits);
        StreamIn1_61 = input_plio::create("StreamIn1_61", adf::plio_32_bits);
        StreamIn1_62 = input_plio::create("StreamIn1_62", adf::plio_32_bits);
        StreamIn1_63 = input_plio::create("StreamIn1_63", adf::plio_32_bits);
        StreamIn1_64 = input_plio::create("StreamIn1_64", adf::plio_32_bits);
        StreamIn1_65 = input_plio::create("StreamIn1_65", adf::plio_32_bits);
        StreamIn1_66 = input_plio::create("StreamIn1_66", adf::plio_32_bits);
        StreamIn1_67 = input_plio::create("StreamIn1_67", adf::plio_32_bits);
        StreamIn1_68 = input_plio::create("StreamIn1_68", adf::plio_32_bits);
        StreamIn1_69 = input_plio::create("StreamIn1_69", adf::plio_32_bits);
        StreamIn1_70 = input_plio::create("StreamIn1_70", adf::plio_32_bits);
        StreamIn1_71 = input_plio::create("StreamIn1_71", adf::plio_32_bits);
        StreamIn1_72 = input_plio::create("StreamIn1_72", adf::plio_32_bits);
        StreamIn1_73 = input_plio::create("StreamIn1_73", adf::plio_32_bits);
        StreamIn1_74 = input_plio::create("StreamIn1_74", adf::plio_32_bits);
        StreamIn1_75 = input_plio::create("StreamIn1_75", adf::plio_32_bits);
        StreamIn1_76 = input_plio::create("StreamIn1_76", adf::plio_32_bits);
        StreamIn1_77 = input_plio::create("StreamIn1_77", adf::plio_32_bits);
        StreamIn1_78 = input_plio::create("StreamIn1_78", adf::plio_32_bits);
        StreamIn1_79 = input_plio::create("StreamIn1_79", adf::plio_32_bits);
        StreamIn1_80 = input_plio::create("StreamIn1_80", adf::plio_32_bits);
        StreamIn1_81 = input_plio::create("StreamIn1_81", adf::plio_32_bits);
        StreamIn1_82 = input_plio::create("StreamIn1_82", adf::plio_32_bits);
        StreamIn1_83 = input_plio::create("StreamIn1_83", adf::plio_32_bits);
        StreamIn1_84 = input_plio::create("StreamIn1_84", adf::plio_32_bits);
        StreamIn1_85 = input_plio::create("StreamIn1_85", adf::plio_32_bits);
        StreamIn1_86 = input_plio::create("StreamIn1_86", adf::plio_32_bits);
        StreamIn1_87 = input_plio::create("StreamIn1_87", adf::plio_32_bits);
        StreamIn1_88 = input_plio::create("StreamIn1_88", adf::plio_32_bits);
        StreamIn1_89 = input_plio::create("StreamIn1_89", adf::plio_32_bits);
        StreamIn1_90 = input_plio::create("StreamIn1_90", adf::plio_32_bits);
        StreamIn1_91 = input_plio::create("StreamIn1_91", adf::plio_32_bits);
        StreamIn1_92 = input_plio::create("StreamIn1_92", adf::plio_32_bits);
        StreamIn1_93 = input_plio::create("StreamIn1_93", adf::plio_32_bits);
        StreamIn1_94 = input_plio::create("StreamIn1_94", adf::plio_32_bits);
        StreamIn1_95 = input_plio::create("StreamIn1_95", adf::plio_32_bits);
    }

    output_streams:
    {
        StreamOut0_0 = output_plio::create("StreamOut0_0", adf::plio_32_bits);
        StreamOut0_1 = output_plio::create("StreamOut0_1", adf::plio_32_bits);
        StreamOut0_2 = output_plio::create("StreamOut0_2", adf::plio_32_bits);
        StreamOut0_3 = output_plio::create("StreamOut0_3", adf::plio_32_bits);
        StreamOut0_4 = output_plio::create("StreamOut0_4", adf::plio_32_bits);
        StreamOut0_5 = output_plio::create("StreamOut0_5", adf::plio_32_bits);
        StreamOut0_6 = output_plio::create("StreamOut0_6", adf::plio_32_bits);
        StreamOut0_7 = output_plio::create("StreamOut0_7", adf::plio_32_bits);
        StreamOut0_8 = output_plio::create("StreamOut0_8", adf::plio_32_bits);
        StreamOut0_9 = output_plio::create("StreamOut0_9", adf::plio_32_bits);
        StreamOut0_10 = output_plio::create("StreamOut0_10", adf::plio_32_bits);
        StreamOut0_11 = output_plio::create("StreamOut0_11", adf::plio_32_bits);
        StreamOut0_12 = output_plio::create("StreamOut0_12", adf::plio_32_bits);
        StreamOut0_13 = output_plio::create("StreamOut0_13", adf::plio_32_bits);
        StreamOut0_14 = output_plio::create("StreamOut0_14", adf::plio_32_bits);
        StreamOut0_15 = output_plio::create("StreamOut0_15", adf::plio_32_bits);
        StreamOut0_16 = output_plio::create("StreamOut0_16", adf::plio_32_bits);
        StreamOut0_17 = output_plio::create("StreamOut0_17", adf::plio_32_bits);
        StreamOut0_18 = output_plio::create("StreamOut0_18", adf::plio_32_bits);
        StreamOut0_19 = output_plio::create("StreamOut0_19", adf::plio_32_bits);
        StreamOut0_20 = output_plio::create("StreamOut0_20", adf::plio_32_bits);
        StreamOut0_21 = output_plio::create("StreamOut0_21", adf::plio_32_bits);
        StreamOut0_22 = output_plio::create("StreamOut0_22", adf::plio_32_bits);
        StreamOut0_23 = output_plio::create("StreamOut0_23", adf::plio_32_bits);
        StreamOut0_24 = output_plio::create("StreamOut0_24", adf::plio_32_bits);
        StreamOut0_25 = output_plio::create("StreamOut0_25", adf::plio_32_bits);
        StreamOut0_26 = output_plio::create("StreamOut0_26", adf::plio_32_bits);
        StreamOut0_27 = output_plio::create("StreamOut0_27", adf::plio_32_bits);
        StreamOut0_28 = output_plio::create("StreamOut0_28", adf::plio_32_bits);
        StreamOut0_29 = output_plio::create("StreamOut0_29", adf::plio_32_bits);
        StreamOut0_30 = output_plio::create("StreamOut0_30", adf::plio_32_bits);
        StreamOut0_31 = output_plio::create("StreamOut0_31", adf::plio_32_bits);
        StreamOut0_32 = output_plio::create("StreamOut0_32", adf::plio_32_bits);
        StreamOut0_33 = output_plio::create("StreamOut0_33", adf::plio_32_bits);
        StreamOut0_34 = output_plio::create("StreamOut0_34", adf::plio_32_bits);
        StreamOut0_35 = output_plio::create("StreamOut0_35", adf::plio_32_bits);
        StreamOut0_36 = output_plio::create("StreamOut0_36", adf::plio_32_bits);
        StreamOut0_37 = output_plio::create("StreamOut0_37", adf::plio_32_bits);
        StreamOut0_38 = output_plio::create("StreamOut0_38", adf::plio_32_bits);
        StreamOut0_39 = output_plio::create("StreamOut0_39", adf::plio_32_bits);
        StreamOut0_40 = output_plio::create("StreamOut0_40", adf::plio_32_bits);
        StreamOut0_41 = output_plio::create("StreamOut0_41", adf::plio_32_bits);
        StreamOut0_42 = output_plio::create("StreamOut0_42", adf::plio_32_bits);
        StreamOut0_43 = output_plio::create("StreamOut0_43", adf::plio_32_bits);
        StreamOut0_44 = output_plio::create("StreamOut0_44", adf::plio_32_bits);
        StreamOut0_45 = output_plio::create("StreamOut0_45", adf::plio_32_bits);
        StreamOut0_46 = output_plio::create("StreamOut0_46", adf::plio_32_bits);
        StreamOut0_47 = output_plio::create("StreamOut0_47", adf::plio_32_bits);
        StreamOut0_48 = output_plio::create("StreamOut0_48", adf::plio_32_bits);
        StreamOut0_49 = output_plio::create("StreamOut0_49", adf::plio_32_bits);
        StreamOut0_50 = output_plio::create("StreamOut0_50", adf::plio_32_bits);
        StreamOut0_51 = output_plio::create("StreamOut0_51", adf::plio_32_bits);
        StreamOut0_52 = output_plio::create("StreamOut0_52", adf::plio_32_bits);
        StreamOut0_53 = output_plio::create("StreamOut0_53", adf::plio_32_bits);
        StreamOut0_54 = output_plio::create("StreamOut0_54", adf::plio_32_bits);
        StreamOut0_55 = output_plio::create("StreamOut0_55", adf::plio_32_bits);
        StreamOut0_56 = output_plio::create("StreamOut0_56", adf::plio_32_bits);
        StreamOut0_57 = output_plio::create("StreamOut0_57", adf::plio_32_bits);
        StreamOut0_58 = output_plio::create("StreamOut0_58", adf::plio_32_bits);
        StreamOut0_59 = output_plio::create("StreamOut0_59", adf::plio_32_bits);
        StreamOut0_60 = output_plio::create("StreamOut0_60", adf::plio_32_bits);
        StreamOut0_61 = output_plio::create("StreamOut0_61", adf::plio_32_bits);
        StreamOut0_62 = output_plio::create("StreamOut0_62", adf::plio_32_bits);
        StreamOut0_63 = output_plio::create("StreamOut0_63", adf::plio_32_bits);
        StreamOut0_64 = output_plio::create("StreamOut0_64", adf::plio_32_bits);
        StreamOut0_65 = output_plio::create("StreamOut0_65", adf::plio_32_bits);
        StreamOut0_66 = output_plio::create("StreamOut0_66", adf::plio_32_bits);
        StreamOut0_67 = output_plio::create("StreamOut0_67", adf::plio_32_bits);
        StreamOut0_68 = output_plio::create("StreamOut0_68", adf::plio_32_bits);
        StreamOut0_69 = output_plio::create("StreamOut0_69", adf::plio_32_bits);
        StreamOut0_70 = output_plio::create("StreamOut0_70", adf::plio_32_bits);
        StreamOut0_71 = output_plio::create("StreamOut0_71", adf::plio_32_bits);
        StreamOut0_72 = output_plio::create("StreamOut0_72", adf::plio_32_bits);
        StreamOut0_73 = output_plio::create("StreamOut0_73", adf::plio_32_bits);
        StreamOut0_74 = output_plio::create("StreamOut0_74", adf::plio_32_bits);
        StreamOut0_75 = output_plio::create("StreamOut0_75", adf::plio_32_bits);
        StreamOut0_76 = output_plio::create("StreamOut0_76", adf::plio_32_bits);
        StreamOut0_77 = output_plio::create("StreamOut0_77", adf::plio_32_bits);
        StreamOut0_78 = output_plio::create("StreamOut0_78", adf::plio_32_bits);
        StreamOut0_79 = output_plio::create("StreamOut0_79", adf::plio_32_bits);
        StreamOut0_80 = output_plio::create("StreamOut0_80", adf::plio_32_bits);
        StreamOut0_81 = output_plio::create("StreamOut0_81", adf::plio_32_bits);
        StreamOut0_82 = output_plio::create("StreamOut0_82", adf::plio_32_bits);
        StreamOut0_83 = output_plio::create("StreamOut0_83", adf::plio_32_bits);
        StreamOut0_84 = output_plio::create("StreamOut0_84", adf::plio_32_bits);
        StreamOut0_85 = output_plio::create("StreamOut0_85", adf::plio_32_bits);
        StreamOut0_86 = output_plio::create("StreamOut0_86", adf::plio_32_bits);
        StreamOut0_87 = output_plio::create("StreamOut0_87", adf::plio_32_bits);
        StreamOut0_88 = output_plio::create("StreamOut0_88", adf::plio_32_bits);
        StreamOut0_89 = output_plio::create("StreamOut0_89", adf::plio_32_bits);
        StreamOut0_90 = output_plio::create("StreamOut0_90", adf::plio_32_bits);
        StreamOut0_91 = output_plio::create("StreamOut0_91", adf::plio_32_bits);
        StreamOut0_92 = output_plio::create("StreamOut0_92", adf::plio_32_bits);
        StreamOut0_93 = output_plio::create("StreamOut0_93", adf::plio_32_bits);
        StreamOut0_94 = output_plio::create("StreamOut0_94", adf::plio_32_bits);
        StreamOut0_95 = output_plio::create("StreamOut0_95", adf::plio_32_bits);
    }

        for (unsigned col = 0; col < COLS; col++)
        {
            for (unsigned subcol_sec = 0; subcol_sec < packet_per_col; subcol_sec++)
            {
                splitter_A[packet_per_col * col + subcol_sec] = pktsplit<rows_per_packet>::create();
                splitter_B[packet_per_col * col + subcol_sec] = pktsplit<rows_per_packet>::create();

                merger[packet_per_col * col + subcol_sec] = pktmerge<rows_per_packet>::create();

                for (unsigned row = 0; row < rows_per_packet; row++)
                {
                    const unsigned index = packet_per_col * rows_per_packet * col + rows_per_packet * subcol_sec + row;

                    vmul[index] = kernel::create(aie_vmul_window);
                    source(vmul[index]) = "vmul.cc";
                    location<kernel>(vmul[index]) = tile(1 /*The 1 is just a shift*/ + col, rows_per_packet * subcol_sec + row);

                    location<buffer>(vmul[index].in[0]) = location<kernel>(vmul[index]);
                    location<buffer>(vmul[index].in[1]) = location<kernel>(vmul[index]);

                    location<buffer>(vmul[index].out[0]) = location<kernel>(vmul[index]);

                    location<stack>(vmul[index]) = location<kernel>(vmul[index]);
                    runtime<ratio>(vmul[index]) = 1;

                    connect<pktstream, window<SIZE / PE * sizeof(float)>>(splitter_A[packet_per_col * col + subcol_sec].out[row], vmul[index].in[0]);
                    connect<pktstream, window<SIZE / PE * sizeof(float)>>(splitter_B[packet_per_col * col + subcol_sec].out[row], vmul[index].in[1]);

                    connect<window<SIZE / PE * sizeof(float)>, pktstream>(vmul[index].out[0], merger[packet_per_col * col + subcol_sec].in[row]);
                }
            }
        }

    unpacking_A:
    {
        connect<pktstream>(StreamIn0_0.out[0], splitter_A[0].in[0]);
        connect<pktstream>(StreamIn0_1.out[0], splitter_A[1].in[0]);
        connect<pktstream>(StreamIn0_2.out[0], splitter_A[2].in[0]);
        connect<pktstream>(StreamIn0_3.out[0], splitter_A[3].in[0]);
        connect<pktstream>(StreamIn0_4.out[0], splitter_A[4].in[0]);
        connect<pktstream>(StreamIn0_5.out[0], splitter_A[5].in[0]);
        connect<pktstream>(StreamIn0_6.out[0], splitter_A[6].in[0]);
        connect<pktstream>(StreamIn0_7.out[0], splitter_A[7].in[0]);
        connect<pktstream>(StreamIn0_8.out[0], splitter_A[8].in[0]);
        connect<pktstream>(StreamIn0_9.out[0], splitter_A[9].in[0]);
        connect<pktstream>(StreamIn0_10.out[0], splitter_A[10].in[0]);
        connect<pktstream>(StreamIn0_11.out[0], splitter_A[11].in[0]);
        connect<pktstream>(StreamIn0_12.out[0], splitter_A[12].in[0]);
        connect<pktstream>(StreamIn0_13.out[0], splitter_A[13].in[0]);
        connect<pktstream>(StreamIn0_14.out[0], splitter_A[14].in[0]);
        connect<pktstream>(StreamIn0_15.out[0], splitter_A[15].in[0]);
        connect<pktstream>(StreamIn0_16.out[0], splitter_A[16].in[0]);
        connect<pktstream>(StreamIn0_17.out[0], splitter_A[17].in[0]);
        connect<pktstream>(StreamIn0_18.out[0], splitter_A[18].in[0]);
        connect<pktstream>(StreamIn0_19.out[0], splitter_A[19].in[0]);
        connect<pktstream>(StreamIn0_20.out[0], splitter_A[20].in[0]);
        connect<pktstream>(StreamIn0_21.out[0], splitter_A[21].in[0]);
        connect<pktstream>(StreamIn0_22.out[0], splitter_A[22].in[0]);
        connect<pktstream>(StreamIn0_23.out[0], splitter_A[23].in[0]);
        connect<pktstream>(StreamIn0_24.out[0], splitter_A[24].in[0]);
        connect<pktstream>(StreamIn0_25.out[0], splitter_A[25].in[0]);
        connect<pktstream>(StreamIn0_26.out[0], splitter_A[26].in[0]);
        connect<pktstream>(StreamIn0_27.out[0], splitter_A[27].in[0]);
        connect<pktstream>(StreamIn0_28.out[0], splitter_A[28].in[0]);
        connect<pktstream>(StreamIn0_29.out[0], splitter_A[29].in[0]);
        connect<pktstream>(StreamIn0_30.out[0], splitter_A[30].in[0]);
        connect<pktstream>(StreamIn0_31.out[0], splitter_A[31].in[0]);
        connect<pktstream>(StreamIn0_32.out[0], splitter_A[32].in[0]);
        connect<pktstream>(StreamIn0_33.out[0], splitter_A[33].in[0]);
        connect<pktstream>(StreamIn0_34.out[0], splitter_A[34].in[0]);
        connect<pktstream>(StreamIn0_35.out[0], splitter_A[35].in[0]);
        connect<pktstream>(StreamIn0_36.out[0], splitter_A[36].in[0]);
        connect<pktstream>(StreamIn0_37.out[0], splitter_A[37].in[0]);
        connect<pktstream>(StreamIn0_38.out[0], splitter_A[38].in[0]);
        connect<pktstream>(StreamIn0_39.out[0], splitter_A[39].in[0]);
        connect<pktstream>(StreamIn0_40.out[0], splitter_A[40].in[0]);
        connect<pktstream>(StreamIn0_41.out[0], splitter_A[41].in[0]);
        connect<pktstream>(StreamIn0_42.out[0], splitter_A[42].in[0]);
        connect<pktstream>(StreamIn0_43.out[0], splitter_A[43].in[0]);
        connect<pktstream>(StreamIn0_44.out[0], splitter_A[44].in[0]);
        connect<pktstream>(StreamIn0_45.out[0], splitter_A[45].in[0]);
        connect<pktstream>(StreamIn0_46.out[0], splitter_A[46].in[0]);
        connect<pktstream>(StreamIn0_47.out[0], splitter_A[47].in[0]);
        connect<pktstream>(StreamIn0_48.out[0], splitter_A[48].in[0]);
        connect<pktstream>(StreamIn0_49.out[0], splitter_A[49].in[0]);
        connect<pktstream>(StreamIn0_50.out[0], splitter_A[50].in[0]);
        connect<pktstream>(StreamIn0_51.out[0], splitter_A[51].in[0]);
        connect<pktstream>(StreamIn0_52.out[0], splitter_A[52].in[0]);
        connect<pktstream>(StreamIn0_53.out[0], splitter_A[53].in[0]);
        connect<pktstream>(StreamIn0_54.out[0], splitter_A[54].in[0]);
        connect<pktstream>(StreamIn0_55.out[0], splitter_A[55].in[0]);
        connect<pktstream>(StreamIn0_56.out[0], splitter_A[56].in[0]);
        connect<pktstream>(StreamIn0_57.out[0], splitter_A[57].in[0]);
        connect<pktstream>(StreamIn0_58.out[0], splitter_A[58].in[0]);
        connect<pktstream>(StreamIn0_59.out[0], splitter_A[59].in[0]);
        connect<pktstream>(StreamIn0_60.out[0], splitter_A[60].in[0]);
        connect<pktstream>(StreamIn0_61.out[0], splitter_A[61].in[0]);
        connect<pktstream>(StreamIn0_62.out[0], splitter_A[62].in[0]);
        connect<pktstream>(StreamIn0_63.out[0], splitter_A[63].in[0]);
        connect<pktstream>(StreamIn0_64.out[0], splitter_A[64].in[0]);
        connect<pktstream>(StreamIn0_65.out[0], splitter_A[65].in[0]);
        connect<pktstream>(StreamIn0_66.out[0], splitter_A[66].in[0]);
        connect<pktstream>(StreamIn0_67.out[0], splitter_A[67].in[0]);
        connect<pktstream>(StreamIn0_68.out[0], splitter_A[68].in[0]);
        connect<pktstream>(StreamIn0_69.out[0], splitter_A[69].in[0]);
        connect<pktstream>(StreamIn0_70.out[0], splitter_A[70].in[0]);
        connect<pktstream>(StreamIn0_71.out[0], splitter_A[71].in[0]);
        connect<pktstream>(StreamIn0_72.out[0], splitter_A[72].in[0]);
        connect<pktstream>(StreamIn0_73.out[0], splitter_A[73].in[0]);
        connect<pktstream>(StreamIn0_74.out[0], splitter_A[74].in[0]);
        connect<pktstream>(StreamIn0_75.out[0], splitter_A[75].in[0]);
        connect<pktstream>(StreamIn0_76.out[0], splitter_A[76].in[0]);
        connect<pktstream>(StreamIn0_77.out[0], splitter_A[77].in[0]);
        connect<pktstream>(StreamIn0_78.out[0], splitter_A[78].in[0]);
        connect<pktstream>(StreamIn0_79.out[0], splitter_A[79].in[0]);
        connect<pktstream>(StreamIn0_80.out[0], splitter_A[80].in[0]);
        connect<pktstream>(StreamIn0_81.out[0], splitter_A[81].in[0]);
        connect<pktstream>(StreamIn0_82.out[0], splitter_A[82].in[0]);
        connect<pktstream>(StreamIn0_83.out[0], splitter_A[83].in[0]);
        connect<pktstream>(StreamIn0_84.out[0], splitter_A[84].in[0]);
        connect<pktstream>(StreamIn0_85.out[0], splitter_A[85].in[0]);
        connect<pktstream>(StreamIn0_86.out[0], splitter_A[86].in[0]);
        connect<pktstream>(StreamIn0_87.out[0], splitter_A[87].in[0]);
        connect<pktstream>(StreamIn0_88.out[0], splitter_A[88].in[0]);
        connect<pktstream>(StreamIn0_89.out[0], splitter_A[89].in[0]);
        connect<pktstream>(StreamIn0_90.out[0], splitter_A[90].in[0]);
        connect<pktstream>(StreamIn0_91.out[0], splitter_A[91].in[0]);
        connect<pktstream>(StreamIn0_92.out[0], splitter_A[92].in[0]);
        connect<pktstream>(StreamIn0_93.out[0], splitter_A[93].in[0]);
        connect<pktstream>(StreamIn0_94.out[0], splitter_A[94].in[0]);
        connect<pktstream>(StreamIn0_95.out[0], splitter_A[95].in[0]);
    }

    unpacking_B:
    {
        connect<pktstream>(StreamIn1_0.out[0], splitter_B[0].in[0]);
        connect<pktstream>(StreamIn1_1.out[0], splitter_B[1].in[0]);
        connect<pktstream>(StreamIn1_2.out[0], splitter_B[2].in[0]);
        connect<pktstream>(StreamIn1_3.out[0], splitter_B[3].in[0]);
        connect<pktstream>(StreamIn1_4.out[0], splitter_B[4].in[0]);
        connect<pktstream>(StreamIn1_5.out[0], splitter_B[5].in[0]);
        connect<pktstream>(StreamIn1_6.out[0], splitter_B[6].in[0]);
        connect<pktstream>(StreamIn1_7.out[0], splitter_B[7].in[0]);
        connect<pktstream>(StreamIn1_8.out[0], splitter_B[8].in[0]);
        connect<pktstream>(StreamIn1_9.out[0], splitter_B[9].in[0]);
        connect<pktstream>(StreamIn1_10.out[0], splitter_B[10].in[0]);
        connect<pktstream>(StreamIn1_11.out[0], splitter_B[11].in[0]);
        connect<pktstream>(StreamIn1_12.out[0], splitter_B[12].in[0]);
        connect<pktstream>(StreamIn1_13.out[0], splitter_B[13].in[0]);
        connect<pktstream>(StreamIn1_14.out[0], splitter_B[14].in[0]);
        connect<pktstream>(StreamIn1_15.out[0], splitter_B[15].in[0]);
        connect<pktstream>(StreamIn1_16.out[0], splitter_B[16].in[0]);
        connect<pktstream>(StreamIn1_17.out[0], splitter_B[17].in[0]);
        connect<pktstream>(StreamIn1_18.out[0], splitter_B[18].in[0]);
        connect<pktstream>(StreamIn1_19.out[0], splitter_B[19].in[0]);
        connect<pktstream>(StreamIn1_20.out[0], splitter_B[20].in[0]);
        connect<pktstream>(StreamIn1_21.out[0], splitter_B[21].in[0]);
        connect<pktstream>(StreamIn1_22.out[0], splitter_B[22].in[0]);
        connect<pktstream>(StreamIn1_23.out[0], splitter_B[23].in[0]);
        connect<pktstream>(StreamIn1_24.out[0], splitter_B[24].in[0]);
        connect<pktstream>(StreamIn1_25.out[0], splitter_B[25].in[0]);
        connect<pktstream>(StreamIn1_26.out[0], splitter_B[26].in[0]);
        connect<pktstream>(StreamIn1_27.out[0], splitter_B[27].in[0]);
        connect<pktstream>(StreamIn1_28.out[0], splitter_B[28].in[0]);
        connect<pktstream>(StreamIn1_29.out[0], splitter_B[29].in[0]);
        connect<pktstream>(StreamIn1_30.out[0], splitter_B[30].in[0]);
        connect<pktstream>(StreamIn1_31.out[0], splitter_B[31].in[0]);
        connect<pktstream>(StreamIn1_32.out[0], splitter_B[32].in[0]);
        connect<pktstream>(StreamIn1_33.out[0], splitter_B[33].in[0]);
        connect<pktstream>(StreamIn1_34.out[0], splitter_B[34].in[0]);
        connect<pktstream>(StreamIn1_35.out[0], splitter_B[35].in[0]);
        connect<pktstream>(StreamIn1_36.out[0], splitter_B[36].in[0]);
        connect<pktstream>(StreamIn1_37.out[0], splitter_B[37].in[0]);
        connect<pktstream>(StreamIn1_38.out[0], splitter_B[38].in[0]);
        connect<pktstream>(StreamIn1_39.out[0], splitter_B[39].in[0]);
        connect<pktstream>(StreamIn1_40.out[0], splitter_B[40].in[0]);
        connect<pktstream>(StreamIn1_41.out[0], splitter_B[41].in[0]);
        connect<pktstream>(StreamIn1_42.out[0], splitter_B[42].in[0]);
        connect<pktstream>(StreamIn1_43.out[0], splitter_B[43].in[0]);
        connect<pktstream>(StreamIn1_44.out[0], splitter_B[44].in[0]);
        connect<pktstream>(StreamIn1_45.out[0], splitter_B[45].in[0]);
        connect<pktstream>(StreamIn1_46.out[0], splitter_B[46].in[0]);
        connect<pktstream>(StreamIn1_47.out[0], splitter_B[47].in[0]);
        connect<pktstream>(StreamIn1_48.out[0], splitter_B[48].in[0]);
        connect<pktstream>(StreamIn1_49.out[0], splitter_B[49].in[0]);
        connect<pktstream>(StreamIn1_50.out[0], splitter_B[50].in[0]);
        connect<pktstream>(StreamIn1_51.out[0], splitter_B[51].in[0]);
        connect<pktstream>(StreamIn1_52.out[0], splitter_B[52].in[0]);
        connect<pktstream>(StreamIn1_53.out[0], splitter_B[53].in[0]);
        connect<pktstream>(StreamIn1_54.out[0], splitter_B[54].in[0]);
        connect<pktstream>(StreamIn1_55.out[0], splitter_B[55].in[0]);
        connect<pktstream>(StreamIn1_56.out[0], splitter_B[56].in[0]);
        connect<pktstream>(StreamIn1_57.out[0], splitter_B[57].in[0]);
        connect<pktstream>(StreamIn1_58.out[0], splitter_B[58].in[0]);
        connect<pktstream>(StreamIn1_59.out[0], splitter_B[59].in[0]);
        connect<pktstream>(StreamIn1_60.out[0], splitter_B[60].in[0]);
        connect<pktstream>(StreamIn1_61.out[0], splitter_B[61].in[0]);
        connect<pktstream>(StreamIn1_62.out[0], splitter_B[62].in[0]);
        connect<pktstream>(StreamIn1_63.out[0], splitter_B[63].in[0]);
        connect<pktstream>(StreamIn1_64.out[0], splitter_B[64].in[0]);
        connect<pktstream>(StreamIn1_65.out[0], splitter_B[65].in[0]);
        connect<pktstream>(StreamIn1_66.out[0], splitter_B[66].in[0]);
        connect<pktstream>(StreamIn1_67.out[0], splitter_B[67].in[0]);
        connect<pktstream>(StreamIn1_68.out[0], splitter_B[68].in[0]);
        connect<pktstream>(StreamIn1_69.out[0], splitter_B[69].in[0]);
        connect<pktstream>(StreamIn1_70.out[0], splitter_B[70].in[0]);
        connect<pktstream>(StreamIn1_71.out[0], splitter_B[71].in[0]);
        connect<pktstream>(StreamIn1_72.out[0], splitter_B[72].in[0]);
        connect<pktstream>(StreamIn1_73.out[0], splitter_B[73].in[0]);
        connect<pktstream>(StreamIn1_74.out[0], splitter_B[74].in[0]);
        connect<pktstream>(StreamIn1_75.out[0], splitter_B[75].in[0]);
        connect<pktstream>(StreamIn1_76.out[0], splitter_B[76].in[0]);
        connect<pktstream>(StreamIn1_77.out[0], splitter_B[77].in[0]);
        connect<pktstream>(StreamIn1_78.out[0], splitter_B[78].in[0]);
        connect<pktstream>(StreamIn1_79.out[0], splitter_B[79].in[0]);
        connect<pktstream>(StreamIn1_80.out[0], splitter_B[80].in[0]);
        connect<pktstream>(StreamIn1_81.out[0], splitter_B[81].in[0]);
        connect<pktstream>(StreamIn1_82.out[0], splitter_B[82].in[0]);
        connect<pktstream>(StreamIn1_83.out[0], splitter_B[83].in[0]);
        connect<pktstream>(StreamIn1_84.out[0], splitter_B[84].in[0]);
        connect<pktstream>(StreamIn1_85.out[0], splitter_B[85].in[0]);
        connect<pktstream>(StreamIn1_86.out[0], splitter_B[86].in[0]);
        connect<pktstream>(StreamIn1_87.out[0], splitter_B[87].in[0]);
        connect<pktstream>(StreamIn1_88.out[0], splitter_B[88].in[0]);
        connect<pktstream>(StreamIn1_89.out[0], splitter_B[89].in[0]);
        connect<pktstream>(StreamIn1_90.out[0], splitter_B[90].in[0]);
        connect<pktstream>(StreamIn1_91.out[0], splitter_B[91].in[0]);
        connect<pktstream>(StreamIn1_92.out[0], splitter_B[92].in[0]);
        connect<pktstream>(StreamIn1_93.out[0], splitter_B[93].in[0]);
        connect<pktstream>(StreamIn1_94.out[0], splitter_B[94].in[0]);
        connect<pktstream>(StreamIn1_95.out[0], splitter_B[95].in[0]);
    }

    packing_C:
    {
        connect<pktstream>(merger[0].out[0], StreamOut0_0.in[0]);
        connect<pktstream>(merger[1].out[0], StreamOut0_1.in[0]);
        connect<pktstream>(merger[2].out[0], StreamOut0_2.in[0]);
        connect<pktstream>(merger[3].out[0], StreamOut0_3.in[0]);
        connect<pktstream>(merger[4].out[0], StreamOut0_4.in[0]);
        connect<pktstream>(merger[5].out[0], StreamOut0_5.in[0]);
        connect<pktstream>(merger[6].out[0], StreamOut0_6.in[0]);
        connect<pktstream>(merger[7].out[0], StreamOut0_7.in[0]);
        connect<pktstream>(merger[8].out[0], StreamOut0_8.in[0]);
        connect<pktstream>(merger[9].out[0], StreamOut0_9.in[0]);
        connect<pktstream>(merger[10].out[0], StreamOut0_10.in[0]);
        connect<pktstream>(merger[11].out[0], StreamOut0_11.in[0]);
        connect<pktstream>(merger[12].out[0], StreamOut0_12.in[0]);
        connect<pktstream>(merger[13].out[0], StreamOut0_13.in[0]);
        connect<pktstream>(merger[14].out[0], StreamOut0_14.in[0]);
        connect<pktstream>(merger[15].out[0], StreamOut0_15.in[0]);
        connect<pktstream>(merger[16].out[0], StreamOut0_16.in[0]);
        connect<pktstream>(merger[17].out[0], StreamOut0_17.in[0]);
        connect<pktstream>(merger[18].out[0], StreamOut0_18.in[0]);
        connect<pktstream>(merger[19].out[0], StreamOut0_19.in[0]);
        connect<pktstream>(merger[20].out[0], StreamOut0_20.in[0]);
        connect<pktstream>(merger[21].out[0], StreamOut0_21.in[0]);
        connect<pktstream>(merger[22].out[0], StreamOut0_22.in[0]);
        connect<pktstream>(merger[23].out[0], StreamOut0_23.in[0]);
        connect<pktstream>(merger[24].out[0], StreamOut0_24.in[0]);
        connect<pktstream>(merger[25].out[0], StreamOut0_25.in[0]);
        connect<pktstream>(merger[26].out[0], StreamOut0_26.in[0]);
        connect<pktstream>(merger[27].out[0], StreamOut0_27.in[0]);
        connect<pktstream>(merger[28].out[0], StreamOut0_28.in[0]);
        connect<pktstream>(merger[29].out[0], StreamOut0_29.in[0]);
        connect<pktstream>(merger[30].out[0], StreamOut0_30.in[0]);
        connect<pktstream>(merger[31].out[0], StreamOut0_31.in[0]);
        connect<pktstream>(merger[32].out[0], StreamOut0_32.in[0]);
        connect<pktstream>(merger[33].out[0], StreamOut0_33.in[0]);
        connect<pktstream>(merger[34].out[0], StreamOut0_34.in[0]);
        connect<pktstream>(merger[35].out[0], StreamOut0_35.in[0]);
        connect<pktstream>(merger[36].out[0], StreamOut0_36.in[0]);
        connect<pktstream>(merger[37].out[0], StreamOut0_37.in[0]);
        connect<pktstream>(merger[38].out[0], StreamOut0_38.in[0]);
        connect<pktstream>(merger[39].out[0], StreamOut0_39.in[0]);
        connect<pktstream>(merger[40].out[0], StreamOut0_40.in[0]);
        connect<pktstream>(merger[41].out[0], StreamOut0_41.in[0]);
        connect<pktstream>(merger[42].out[0], StreamOut0_42.in[0]);
        connect<pktstream>(merger[43].out[0], StreamOut0_43.in[0]);
        connect<pktstream>(merger[44].out[0], StreamOut0_44.in[0]);
        connect<pktstream>(merger[45].out[0], StreamOut0_45.in[0]);
        connect<pktstream>(merger[46].out[0], StreamOut0_46.in[0]);
        connect<pktstream>(merger[47].out[0], StreamOut0_47.in[0]);
        connect<pktstream>(merger[48].out[0], StreamOut0_48.in[0]);
        connect<pktstream>(merger[49].out[0], StreamOut0_49.in[0]);
        connect<pktstream>(merger[50].out[0], StreamOut0_50.in[0]);
        connect<pktstream>(merger[51].out[0], StreamOut0_51.in[0]);
        connect<pktstream>(merger[52].out[0], StreamOut0_52.in[0]);
        connect<pktstream>(merger[53].out[0], StreamOut0_53.in[0]);
        connect<pktstream>(merger[54].out[0], StreamOut0_54.in[0]);
        connect<pktstream>(merger[55].out[0], StreamOut0_55.in[0]);
        connect<pktstream>(merger[56].out[0], StreamOut0_56.in[0]);
        connect<pktstream>(merger[57].out[0], StreamOut0_57.in[0]);
        connect<pktstream>(merger[58].out[0], StreamOut0_58.in[0]);
        connect<pktstream>(merger[59].out[0], StreamOut0_59.in[0]);
        connect<pktstream>(merger[60].out[0], StreamOut0_60.in[0]);
        connect<pktstream>(merger[61].out[0], StreamOut0_61.in[0]);
        connect<pktstream>(merger[62].out[0], StreamOut0_62.in[0]);
        connect<pktstream>(merger[63].out[0], StreamOut0_63.in[0]);
        connect<pktstream>(merger[64].out[0], StreamOut0_64.in[0]);
        connect<pktstream>(merger[65].out[0], StreamOut0_65.in[0]);
        connect<pktstream>(merger[66].out[0], StreamOut0_66.in[0]);
        connect<pktstream>(merger[67].out[0], StreamOut0_67.in[0]);
        connect<pktstream>(merger[68].out[0], StreamOut0_68.in[0]);
        connect<pktstream>(merger[69].out[0], StreamOut0_69.in[0]);
        connect<pktstream>(merger[70].out[0], StreamOut0_70.in[0]);
        connect<pktstream>(merger[71].out[0], StreamOut0_71.in[0]);
        connect<pktstream>(merger[72].out[0], StreamOut0_72.in[0]);
        connect<pktstream>(merger[73].out[0], StreamOut0_73.in[0]);
        connect<pktstream>(merger[74].out[0], StreamOut0_74.in[0]);
        connect<pktstream>(merger[75].out[0], StreamOut0_75.in[0]);
        connect<pktstream>(merger[76].out[0], StreamOut0_76.in[0]);
        connect<pktstream>(merger[77].out[0], StreamOut0_77.in[0]);
        connect<pktstream>(merger[78].out[0], StreamOut0_78.in[0]);
        connect<pktstream>(merger[79].out[0], StreamOut0_79.in[0]);
        connect<pktstream>(merger[80].out[0], StreamOut0_80.in[0]);
        connect<pktstream>(merger[81].out[0], StreamOut0_81.in[0]);
        connect<pktstream>(merger[82].out[0], StreamOut0_82.in[0]);
        connect<pktstream>(merger[83].out[0], StreamOut0_83.in[0]);
        connect<pktstream>(merger[84].out[0], StreamOut0_84.in[0]);
        connect<pktstream>(merger[85].out[0], StreamOut0_85.in[0]);
        connect<pktstream>(merger[86].out[0], StreamOut0_86.in[0]);
        connect<pktstream>(merger[87].out[0], StreamOut0_87.in[0]);
        connect<pktstream>(merger[88].out[0], StreamOut0_88.in[0]);
        connect<pktstream>(merger[89].out[0], StreamOut0_89.in[0]);
        connect<pktstream>(merger[90].out[0], StreamOut0_90.in[0]);
        connect<pktstream>(merger[91].out[0], StreamOut0_91.in[0]);
        connect<pktstream>(merger[92].out[0], StreamOut0_92.in[0]);
        connect<pktstream>(merger[93].out[0], StreamOut0_93.in[0]);
        connect<pktstream>(merger[94].out[0], StreamOut0_94.in[0]);
        connect<pktstream>(merger[95].out[0], StreamOut0_95.in[0]);
    }
    };
};

#endif
