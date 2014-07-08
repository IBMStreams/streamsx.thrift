# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.streams_boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.streams_boost.org for most recent version. */
#
# ifndef STREAMS_BOOST_PREPROCESSOR_SEQ_ENUM_HPP
# define STREAMS_BOOST_PREPROCESSOR_SEQ_ENUM_HPP
#
# include <streams_boost/preprocessor/cat.hpp>
# include <streams_boost/preprocessor/config/config.hpp>
# include <streams_boost/preprocessor/seq/size.hpp>
#
# /* STREAMS_BOOST_PP_SEQ_ENUM */
#
# if STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_EDG()
#    define STREAMS_BOOST_PP_SEQ_ENUM(seq) STREAMS_BOOST_PP_SEQ_ENUM_I(seq)
#    define STREAMS_BOOST_PP_SEQ_ENUM_I(seq) STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_SEQ_ENUM_, STREAMS_BOOST_PP_SEQ_SIZE(seq)) seq
# elif STREAMS_BOOST_PP_CONFIG_FLAGS() & STREAMS_BOOST_PP_CONFIG_MWCC()
#    define STREAMS_BOOST_PP_SEQ_ENUM(seq) STREAMS_BOOST_PP_SEQ_ENUM_I(STREAMS_BOOST_PP_SEQ_SIZE(seq), seq)
#    define STREAMS_BOOST_PP_SEQ_ENUM_I(size, seq) STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_SEQ_ENUM_, size) seq
# else
#    define STREAMS_BOOST_PP_SEQ_ENUM(seq) STREAMS_BOOST_PP_CAT(STREAMS_BOOST_PP_SEQ_ENUM_, STREAMS_BOOST_PP_SEQ_SIZE(seq)) seq
# endif
#
# define STREAMS_BOOST_PP_SEQ_ENUM_1(x) x
# define STREAMS_BOOST_PP_SEQ_ENUM_2(x) x, STREAMS_BOOST_PP_SEQ_ENUM_1
# define STREAMS_BOOST_PP_SEQ_ENUM_3(x) x, STREAMS_BOOST_PP_SEQ_ENUM_2
# define STREAMS_BOOST_PP_SEQ_ENUM_4(x) x, STREAMS_BOOST_PP_SEQ_ENUM_3
# define STREAMS_BOOST_PP_SEQ_ENUM_5(x) x, STREAMS_BOOST_PP_SEQ_ENUM_4
# define STREAMS_BOOST_PP_SEQ_ENUM_6(x) x, STREAMS_BOOST_PP_SEQ_ENUM_5
# define STREAMS_BOOST_PP_SEQ_ENUM_7(x) x, STREAMS_BOOST_PP_SEQ_ENUM_6
# define STREAMS_BOOST_PP_SEQ_ENUM_8(x) x, STREAMS_BOOST_PP_SEQ_ENUM_7
# define STREAMS_BOOST_PP_SEQ_ENUM_9(x) x, STREAMS_BOOST_PP_SEQ_ENUM_8
# define STREAMS_BOOST_PP_SEQ_ENUM_10(x) x, STREAMS_BOOST_PP_SEQ_ENUM_9
# define STREAMS_BOOST_PP_SEQ_ENUM_11(x) x, STREAMS_BOOST_PP_SEQ_ENUM_10
# define STREAMS_BOOST_PP_SEQ_ENUM_12(x) x, STREAMS_BOOST_PP_SEQ_ENUM_11
# define STREAMS_BOOST_PP_SEQ_ENUM_13(x) x, STREAMS_BOOST_PP_SEQ_ENUM_12
# define STREAMS_BOOST_PP_SEQ_ENUM_14(x) x, STREAMS_BOOST_PP_SEQ_ENUM_13
# define STREAMS_BOOST_PP_SEQ_ENUM_15(x) x, STREAMS_BOOST_PP_SEQ_ENUM_14
# define STREAMS_BOOST_PP_SEQ_ENUM_16(x) x, STREAMS_BOOST_PP_SEQ_ENUM_15
# define STREAMS_BOOST_PP_SEQ_ENUM_17(x) x, STREAMS_BOOST_PP_SEQ_ENUM_16
# define STREAMS_BOOST_PP_SEQ_ENUM_18(x) x, STREAMS_BOOST_PP_SEQ_ENUM_17
# define STREAMS_BOOST_PP_SEQ_ENUM_19(x) x, STREAMS_BOOST_PP_SEQ_ENUM_18
# define STREAMS_BOOST_PP_SEQ_ENUM_20(x) x, STREAMS_BOOST_PP_SEQ_ENUM_19
# define STREAMS_BOOST_PP_SEQ_ENUM_21(x) x, STREAMS_BOOST_PP_SEQ_ENUM_20
# define STREAMS_BOOST_PP_SEQ_ENUM_22(x) x, STREAMS_BOOST_PP_SEQ_ENUM_21
# define STREAMS_BOOST_PP_SEQ_ENUM_23(x) x, STREAMS_BOOST_PP_SEQ_ENUM_22
# define STREAMS_BOOST_PP_SEQ_ENUM_24(x) x, STREAMS_BOOST_PP_SEQ_ENUM_23
# define STREAMS_BOOST_PP_SEQ_ENUM_25(x) x, STREAMS_BOOST_PP_SEQ_ENUM_24
# define STREAMS_BOOST_PP_SEQ_ENUM_26(x) x, STREAMS_BOOST_PP_SEQ_ENUM_25
# define STREAMS_BOOST_PP_SEQ_ENUM_27(x) x, STREAMS_BOOST_PP_SEQ_ENUM_26
# define STREAMS_BOOST_PP_SEQ_ENUM_28(x) x, STREAMS_BOOST_PP_SEQ_ENUM_27
# define STREAMS_BOOST_PP_SEQ_ENUM_29(x) x, STREAMS_BOOST_PP_SEQ_ENUM_28
# define STREAMS_BOOST_PP_SEQ_ENUM_30(x) x, STREAMS_BOOST_PP_SEQ_ENUM_29
# define STREAMS_BOOST_PP_SEQ_ENUM_31(x) x, STREAMS_BOOST_PP_SEQ_ENUM_30
# define STREAMS_BOOST_PP_SEQ_ENUM_32(x) x, STREAMS_BOOST_PP_SEQ_ENUM_31
# define STREAMS_BOOST_PP_SEQ_ENUM_33(x) x, STREAMS_BOOST_PP_SEQ_ENUM_32
# define STREAMS_BOOST_PP_SEQ_ENUM_34(x) x, STREAMS_BOOST_PP_SEQ_ENUM_33
# define STREAMS_BOOST_PP_SEQ_ENUM_35(x) x, STREAMS_BOOST_PP_SEQ_ENUM_34
# define STREAMS_BOOST_PP_SEQ_ENUM_36(x) x, STREAMS_BOOST_PP_SEQ_ENUM_35
# define STREAMS_BOOST_PP_SEQ_ENUM_37(x) x, STREAMS_BOOST_PP_SEQ_ENUM_36
# define STREAMS_BOOST_PP_SEQ_ENUM_38(x) x, STREAMS_BOOST_PP_SEQ_ENUM_37
# define STREAMS_BOOST_PP_SEQ_ENUM_39(x) x, STREAMS_BOOST_PP_SEQ_ENUM_38
# define STREAMS_BOOST_PP_SEQ_ENUM_40(x) x, STREAMS_BOOST_PP_SEQ_ENUM_39
# define STREAMS_BOOST_PP_SEQ_ENUM_41(x) x, STREAMS_BOOST_PP_SEQ_ENUM_40
# define STREAMS_BOOST_PP_SEQ_ENUM_42(x) x, STREAMS_BOOST_PP_SEQ_ENUM_41
# define STREAMS_BOOST_PP_SEQ_ENUM_43(x) x, STREAMS_BOOST_PP_SEQ_ENUM_42
# define STREAMS_BOOST_PP_SEQ_ENUM_44(x) x, STREAMS_BOOST_PP_SEQ_ENUM_43
# define STREAMS_BOOST_PP_SEQ_ENUM_45(x) x, STREAMS_BOOST_PP_SEQ_ENUM_44
# define STREAMS_BOOST_PP_SEQ_ENUM_46(x) x, STREAMS_BOOST_PP_SEQ_ENUM_45
# define STREAMS_BOOST_PP_SEQ_ENUM_47(x) x, STREAMS_BOOST_PP_SEQ_ENUM_46
# define STREAMS_BOOST_PP_SEQ_ENUM_48(x) x, STREAMS_BOOST_PP_SEQ_ENUM_47
# define STREAMS_BOOST_PP_SEQ_ENUM_49(x) x, STREAMS_BOOST_PP_SEQ_ENUM_48
# define STREAMS_BOOST_PP_SEQ_ENUM_50(x) x, STREAMS_BOOST_PP_SEQ_ENUM_49
# define STREAMS_BOOST_PP_SEQ_ENUM_51(x) x, STREAMS_BOOST_PP_SEQ_ENUM_50
# define STREAMS_BOOST_PP_SEQ_ENUM_52(x) x, STREAMS_BOOST_PP_SEQ_ENUM_51
# define STREAMS_BOOST_PP_SEQ_ENUM_53(x) x, STREAMS_BOOST_PP_SEQ_ENUM_52
# define STREAMS_BOOST_PP_SEQ_ENUM_54(x) x, STREAMS_BOOST_PP_SEQ_ENUM_53
# define STREAMS_BOOST_PP_SEQ_ENUM_55(x) x, STREAMS_BOOST_PP_SEQ_ENUM_54
# define STREAMS_BOOST_PP_SEQ_ENUM_56(x) x, STREAMS_BOOST_PP_SEQ_ENUM_55
# define STREAMS_BOOST_PP_SEQ_ENUM_57(x) x, STREAMS_BOOST_PP_SEQ_ENUM_56
# define STREAMS_BOOST_PP_SEQ_ENUM_58(x) x, STREAMS_BOOST_PP_SEQ_ENUM_57
# define STREAMS_BOOST_PP_SEQ_ENUM_59(x) x, STREAMS_BOOST_PP_SEQ_ENUM_58
# define STREAMS_BOOST_PP_SEQ_ENUM_60(x) x, STREAMS_BOOST_PP_SEQ_ENUM_59
# define STREAMS_BOOST_PP_SEQ_ENUM_61(x) x, STREAMS_BOOST_PP_SEQ_ENUM_60
# define STREAMS_BOOST_PP_SEQ_ENUM_62(x) x, STREAMS_BOOST_PP_SEQ_ENUM_61
# define STREAMS_BOOST_PP_SEQ_ENUM_63(x) x, STREAMS_BOOST_PP_SEQ_ENUM_62
# define STREAMS_BOOST_PP_SEQ_ENUM_64(x) x, STREAMS_BOOST_PP_SEQ_ENUM_63
# define STREAMS_BOOST_PP_SEQ_ENUM_65(x) x, STREAMS_BOOST_PP_SEQ_ENUM_64
# define STREAMS_BOOST_PP_SEQ_ENUM_66(x) x, STREAMS_BOOST_PP_SEQ_ENUM_65
# define STREAMS_BOOST_PP_SEQ_ENUM_67(x) x, STREAMS_BOOST_PP_SEQ_ENUM_66
# define STREAMS_BOOST_PP_SEQ_ENUM_68(x) x, STREAMS_BOOST_PP_SEQ_ENUM_67
# define STREAMS_BOOST_PP_SEQ_ENUM_69(x) x, STREAMS_BOOST_PP_SEQ_ENUM_68
# define STREAMS_BOOST_PP_SEQ_ENUM_70(x) x, STREAMS_BOOST_PP_SEQ_ENUM_69
# define STREAMS_BOOST_PP_SEQ_ENUM_71(x) x, STREAMS_BOOST_PP_SEQ_ENUM_70
# define STREAMS_BOOST_PP_SEQ_ENUM_72(x) x, STREAMS_BOOST_PP_SEQ_ENUM_71
# define STREAMS_BOOST_PP_SEQ_ENUM_73(x) x, STREAMS_BOOST_PP_SEQ_ENUM_72
# define STREAMS_BOOST_PP_SEQ_ENUM_74(x) x, STREAMS_BOOST_PP_SEQ_ENUM_73
# define STREAMS_BOOST_PP_SEQ_ENUM_75(x) x, STREAMS_BOOST_PP_SEQ_ENUM_74
# define STREAMS_BOOST_PP_SEQ_ENUM_76(x) x, STREAMS_BOOST_PP_SEQ_ENUM_75
# define STREAMS_BOOST_PP_SEQ_ENUM_77(x) x, STREAMS_BOOST_PP_SEQ_ENUM_76
# define STREAMS_BOOST_PP_SEQ_ENUM_78(x) x, STREAMS_BOOST_PP_SEQ_ENUM_77
# define STREAMS_BOOST_PP_SEQ_ENUM_79(x) x, STREAMS_BOOST_PP_SEQ_ENUM_78
# define STREAMS_BOOST_PP_SEQ_ENUM_80(x) x, STREAMS_BOOST_PP_SEQ_ENUM_79
# define STREAMS_BOOST_PP_SEQ_ENUM_81(x) x, STREAMS_BOOST_PP_SEQ_ENUM_80
# define STREAMS_BOOST_PP_SEQ_ENUM_82(x) x, STREAMS_BOOST_PP_SEQ_ENUM_81
# define STREAMS_BOOST_PP_SEQ_ENUM_83(x) x, STREAMS_BOOST_PP_SEQ_ENUM_82
# define STREAMS_BOOST_PP_SEQ_ENUM_84(x) x, STREAMS_BOOST_PP_SEQ_ENUM_83
# define STREAMS_BOOST_PP_SEQ_ENUM_85(x) x, STREAMS_BOOST_PP_SEQ_ENUM_84
# define STREAMS_BOOST_PP_SEQ_ENUM_86(x) x, STREAMS_BOOST_PP_SEQ_ENUM_85
# define STREAMS_BOOST_PP_SEQ_ENUM_87(x) x, STREAMS_BOOST_PP_SEQ_ENUM_86
# define STREAMS_BOOST_PP_SEQ_ENUM_88(x) x, STREAMS_BOOST_PP_SEQ_ENUM_87
# define STREAMS_BOOST_PP_SEQ_ENUM_89(x) x, STREAMS_BOOST_PP_SEQ_ENUM_88
# define STREAMS_BOOST_PP_SEQ_ENUM_90(x) x, STREAMS_BOOST_PP_SEQ_ENUM_89
# define STREAMS_BOOST_PP_SEQ_ENUM_91(x) x, STREAMS_BOOST_PP_SEQ_ENUM_90
# define STREAMS_BOOST_PP_SEQ_ENUM_92(x) x, STREAMS_BOOST_PP_SEQ_ENUM_91
# define STREAMS_BOOST_PP_SEQ_ENUM_93(x) x, STREAMS_BOOST_PP_SEQ_ENUM_92
# define STREAMS_BOOST_PP_SEQ_ENUM_94(x) x, STREAMS_BOOST_PP_SEQ_ENUM_93
# define STREAMS_BOOST_PP_SEQ_ENUM_95(x) x, STREAMS_BOOST_PP_SEQ_ENUM_94
# define STREAMS_BOOST_PP_SEQ_ENUM_96(x) x, STREAMS_BOOST_PP_SEQ_ENUM_95
# define STREAMS_BOOST_PP_SEQ_ENUM_97(x) x, STREAMS_BOOST_PP_SEQ_ENUM_96
# define STREAMS_BOOST_PP_SEQ_ENUM_98(x) x, STREAMS_BOOST_PP_SEQ_ENUM_97
# define STREAMS_BOOST_PP_SEQ_ENUM_99(x) x, STREAMS_BOOST_PP_SEQ_ENUM_98
# define STREAMS_BOOST_PP_SEQ_ENUM_100(x) x, STREAMS_BOOST_PP_SEQ_ENUM_99
# define STREAMS_BOOST_PP_SEQ_ENUM_101(x) x, STREAMS_BOOST_PP_SEQ_ENUM_100
# define STREAMS_BOOST_PP_SEQ_ENUM_102(x) x, STREAMS_BOOST_PP_SEQ_ENUM_101
# define STREAMS_BOOST_PP_SEQ_ENUM_103(x) x, STREAMS_BOOST_PP_SEQ_ENUM_102
# define STREAMS_BOOST_PP_SEQ_ENUM_104(x) x, STREAMS_BOOST_PP_SEQ_ENUM_103
# define STREAMS_BOOST_PP_SEQ_ENUM_105(x) x, STREAMS_BOOST_PP_SEQ_ENUM_104
# define STREAMS_BOOST_PP_SEQ_ENUM_106(x) x, STREAMS_BOOST_PP_SEQ_ENUM_105
# define STREAMS_BOOST_PP_SEQ_ENUM_107(x) x, STREAMS_BOOST_PP_SEQ_ENUM_106
# define STREAMS_BOOST_PP_SEQ_ENUM_108(x) x, STREAMS_BOOST_PP_SEQ_ENUM_107
# define STREAMS_BOOST_PP_SEQ_ENUM_109(x) x, STREAMS_BOOST_PP_SEQ_ENUM_108
# define STREAMS_BOOST_PP_SEQ_ENUM_110(x) x, STREAMS_BOOST_PP_SEQ_ENUM_109
# define STREAMS_BOOST_PP_SEQ_ENUM_111(x) x, STREAMS_BOOST_PP_SEQ_ENUM_110
# define STREAMS_BOOST_PP_SEQ_ENUM_112(x) x, STREAMS_BOOST_PP_SEQ_ENUM_111
# define STREAMS_BOOST_PP_SEQ_ENUM_113(x) x, STREAMS_BOOST_PP_SEQ_ENUM_112
# define STREAMS_BOOST_PP_SEQ_ENUM_114(x) x, STREAMS_BOOST_PP_SEQ_ENUM_113
# define STREAMS_BOOST_PP_SEQ_ENUM_115(x) x, STREAMS_BOOST_PP_SEQ_ENUM_114
# define STREAMS_BOOST_PP_SEQ_ENUM_116(x) x, STREAMS_BOOST_PP_SEQ_ENUM_115
# define STREAMS_BOOST_PP_SEQ_ENUM_117(x) x, STREAMS_BOOST_PP_SEQ_ENUM_116
# define STREAMS_BOOST_PP_SEQ_ENUM_118(x) x, STREAMS_BOOST_PP_SEQ_ENUM_117
# define STREAMS_BOOST_PP_SEQ_ENUM_119(x) x, STREAMS_BOOST_PP_SEQ_ENUM_118
# define STREAMS_BOOST_PP_SEQ_ENUM_120(x) x, STREAMS_BOOST_PP_SEQ_ENUM_119
# define STREAMS_BOOST_PP_SEQ_ENUM_121(x) x, STREAMS_BOOST_PP_SEQ_ENUM_120
# define STREAMS_BOOST_PP_SEQ_ENUM_122(x) x, STREAMS_BOOST_PP_SEQ_ENUM_121
# define STREAMS_BOOST_PP_SEQ_ENUM_123(x) x, STREAMS_BOOST_PP_SEQ_ENUM_122
# define STREAMS_BOOST_PP_SEQ_ENUM_124(x) x, STREAMS_BOOST_PP_SEQ_ENUM_123
# define STREAMS_BOOST_PP_SEQ_ENUM_125(x) x, STREAMS_BOOST_PP_SEQ_ENUM_124
# define STREAMS_BOOST_PP_SEQ_ENUM_126(x) x, STREAMS_BOOST_PP_SEQ_ENUM_125
# define STREAMS_BOOST_PP_SEQ_ENUM_127(x) x, STREAMS_BOOST_PP_SEQ_ENUM_126
# define STREAMS_BOOST_PP_SEQ_ENUM_128(x) x, STREAMS_BOOST_PP_SEQ_ENUM_127
# define STREAMS_BOOST_PP_SEQ_ENUM_129(x) x, STREAMS_BOOST_PP_SEQ_ENUM_128
# define STREAMS_BOOST_PP_SEQ_ENUM_130(x) x, STREAMS_BOOST_PP_SEQ_ENUM_129
# define STREAMS_BOOST_PP_SEQ_ENUM_131(x) x, STREAMS_BOOST_PP_SEQ_ENUM_130
# define STREAMS_BOOST_PP_SEQ_ENUM_132(x) x, STREAMS_BOOST_PP_SEQ_ENUM_131
# define STREAMS_BOOST_PP_SEQ_ENUM_133(x) x, STREAMS_BOOST_PP_SEQ_ENUM_132
# define STREAMS_BOOST_PP_SEQ_ENUM_134(x) x, STREAMS_BOOST_PP_SEQ_ENUM_133
# define STREAMS_BOOST_PP_SEQ_ENUM_135(x) x, STREAMS_BOOST_PP_SEQ_ENUM_134
# define STREAMS_BOOST_PP_SEQ_ENUM_136(x) x, STREAMS_BOOST_PP_SEQ_ENUM_135
# define STREAMS_BOOST_PP_SEQ_ENUM_137(x) x, STREAMS_BOOST_PP_SEQ_ENUM_136
# define STREAMS_BOOST_PP_SEQ_ENUM_138(x) x, STREAMS_BOOST_PP_SEQ_ENUM_137
# define STREAMS_BOOST_PP_SEQ_ENUM_139(x) x, STREAMS_BOOST_PP_SEQ_ENUM_138
# define STREAMS_BOOST_PP_SEQ_ENUM_140(x) x, STREAMS_BOOST_PP_SEQ_ENUM_139
# define STREAMS_BOOST_PP_SEQ_ENUM_141(x) x, STREAMS_BOOST_PP_SEQ_ENUM_140
# define STREAMS_BOOST_PP_SEQ_ENUM_142(x) x, STREAMS_BOOST_PP_SEQ_ENUM_141
# define STREAMS_BOOST_PP_SEQ_ENUM_143(x) x, STREAMS_BOOST_PP_SEQ_ENUM_142
# define STREAMS_BOOST_PP_SEQ_ENUM_144(x) x, STREAMS_BOOST_PP_SEQ_ENUM_143
# define STREAMS_BOOST_PP_SEQ_ENUM_145(x) x, STREAMS_BOOST_PP_SEQ_ENUM_144
# define STREAMS_BOOST_PP_SEQ_ENUM_146(x) x, STREAMS_BOOST_PP_SEQ_ENUM_145
# define STREAMS_BOOST_PP_SEQ_ENUM_147(x) x, STREAMS_BOOST_PP_SEQ_ENUM_146
# define STREAMS_BOOST_PP_SEQ_ENUM_148(x) x, STREAMS_BOOST_PP_SEQ_ENUM_147
# define STREAMS_BOOST_PP_SEQ_ENUM_149(x) x, STREAMS_BOOST_PP_SEQ_ENUM_148
# define STREAMS_BOOST_PP_SEQ_ENUM_150(x) x, STREAMS_BOOST_PP_SEQ_ENUM_149
# define STREAMS_BOOST_PP_SEQ_ENUM_151(x) x, STREAMS_BOOST_PP_SEQ_ENUM_150
# define STREAMS_BOOST_PP_SEQ_ENUM_152(x) x, STREAMS_BOOST_PP_SEQ_ENUM_151
# define STREAMS_BOOST_PP_SEQ_ENUM_153(x) x, STREAMS_BOOST_PP_SEQ_ENUM_152
# define STREAMS_BOOST_PP_SEQ_ENUM_154(x) x, STREAMS_BOOST_PP_SEQ_ENUM_153
# define STREAMS_BOOST_PP_SEQ_ENUM_155(x) x, STREAMS_BOOST_PP_SEQ_ENUM_154
# define STREAMS_BOOST_PP_SEQ_ENUM_156(x) x, STREAMS_BOOST_PP_SEQ_ENUM_155
# define STREAMS_BOOST_PP_SEQ_ENUM_157(x) x, STREAMS_BOOST_PP_SEQ_ENUM_156
# define STREAMS_BOOST_PP_SEQ_ENUM_158(x) x, STREAMS_BOOST_PP_SEQ_ENUM_157
# define STREAMS_BOOST_PP_SEQ_ENUM_159(x) x, STREAMS_BOOST_PP_SEQ_ENUM_158
# define STREAMS_BOOST_PP_SEQ_ENUM_160(x) x, STREAMS_BOOST_PP_SEQ_ENUM_159
# define STREAMS_BOOST_PP_SEQ_ENUM_161(x) x, STREAMS_BOOST_PP_SEQ_ENUM_160
# define STREAMS_BOOST_PP_SEQ_ENUM_162(x) x, STREAMS_BOOST_PP_SEQ_ENUM_161
# define STREAMS_BOOST_PP_SEQ_ENUM_163(x) x, STREAMS_BOOST_PP_SEQ_ENUM_162
# define STREAMS_BOOST_PP_SEQ_ENUM_164(x) x, STREAMS_BOOST_PP_SEQ_ENUM_163
# define STREAMS_BOOST_PP_SEQ_ENUM_165(x) x, STREAMS_BOOST_PP_SEQ_ENUM_164
# define STREAMS_BOOST_PP_SEQ_ENUM_166(x) x, STREAMS_BOOST_PP_SEQ_ENUM_165
# define STREAMS_BOOST_PP_SEQ_ENUM_167(x) x, STREAMS_BOOST_PP_SEQ_ENUM_166
# define STREAMS_BOOST_PP_SEQ_ENUM_168(x) x, STREAMS_BOOST_PP_SEQ_ENUM_167
# define STREAMS_BOOST_PP_SEQ_ENUM_169(x) x, STREAMS_BOOST_PP_SEQ_ENUM_168
# define STREAMS_BOOST_PP_SEQ_ENUM_170(x) x, STREAMS_BOOST_PP_SEQ_ENUM_169
# define STREAMS_BOOST_PP_SEQ_ENUM_171(x) x, STREAMS_BOOST_PP_SEQ_ENUM_170
# define STREAMS_BOOST_PP_SEQ_ENUM_172(x) x, STREAMS_BOOST_PP_SEQ_ENUM_171
# define STREAMS_BOOST_PP_SEQ_ENUM_173(x) x, STREAMS_BOOST_PP_SEQ_ENUM_172
# define STREAMS_BOOST_PP_SEQ_ENUM_174(x) x, STREAMS_BOOST_PP_SEQ_ENUM_173
# define STREAMS_BOOST_PP_SEQ_ENUM_175(x) x, STREAMS_BOOST_PP_SEQ_ENUM_174
# define STREAMS_BOOST_PP_SEQ_ENUM_176(x) x, STREAMS_BOOST_PP_SEQ_ENUM_175
# define STREAMS_BOOST_PP_SEQ_ENUM_177(x) x, STREAMS_BOOST_PP_SEQ_ENUM_176
# define STREAMS_BOOST_PP_SEQ_ENUM_178(x) x, STREAMS_BOOST_PP_SEQ_ENUM_177
# define STREAMS_BOOST_PP_SEQ_ENUM_179(x) x, STREAMS_BOOST_PP_SEQ_ENUM_178
# define STREAMS_BOOST_PP_SEQ_ENUM_180(x) x, STREAMS_BOOST_PP_SEQ_ENUM_179
# define STREAMS_BOOST_PP_SEQ_ENUM_181(x) x, STREAMS_BOOST_PP_SEQ_ENUM_180
# define STREAMS_BOOST_PP_SEQ_ENUM_182(x) x, STREAMS_BOOST_PP_SEQ_ENUM_181
# define STREAMS_BOOST_PP_SEQ_ENUM_183(x) x, STREAMS_BOOST_PP_SEQ_ENUM_182
# define STREAMS_BOOST_PP_SEQ_ENUM_184(x) x, STREAMS_BOOST_PP_SEQ_ENUM_183
# define STREAMS_BOOST_PP_SEQ_ENUM_185(x) x, STREAMS_BOOST_PP_SEQ_ENUM_184
# define STREAMS_BOOST_PP_SEQ_ENUM_186(x) x, STREAMS_BOOST_PP_SEQ_ENUM_185
# define STREAMS_BOOST_PP_SEQ_ENUM_187(x) x, STREAMS_BOOST_PP_SEQ_ENUM_186
# define STREAMS_BOOST_PP_SEQ_ENUM_188(x) x, STREAMS_BOOST_PP_SEQ_ENUM_187
# define STREAMS_BOOST_PP_SEQ_ENUM_189(x) x, STREAMS_BOOST_PP_SEQ_ENUM_188
# define STREAMS_BOOST_PP_SEQ_ENUM_190(x) x, STREAMS_BOOST_PP_SEQ_ENUM_189
# define STREAMS_BOOST_PP_SEQ_ENUM_191(x) x, STREAMS_BOOST_PP_SEQ_ENUM_190
# define STREAMS_BOOST_PP_SEQ_ENUM_192(x) x, STREAMS_BOOST_PP_SEQ_ENUM_191
# define STREAMS_BOOST_PP_SEQ_ENUM_193(x) x, STREAMS_BOOST_PP_SEQ_ENUM_192
# define STREAMS_BOOST_PP_SEQ_ENUM_194(x) x, STREAMS_BOOST_PP_SEQ_ENUM_193
# define STREAMS_BOOST_PP_SEQ_ENUM_195(x) x, STREAMS_BOOST_PP_SEQ_ENUM_194
# define STREAMS_BOOST_PP_SEQ_ENUM_196(x) x, STREAMS_BOOST_PP_SEQ_ENUM_195
# define STREAMS_BOOST_PP_SEQ_ENUM_197(x) x, STREAMS_BOOST_PP_SEQ_ENUM_196
# define STREAMS_BOOST_PP_SEQ_ENUM_198(x) x, STREAMS_BOOST_PP_SEQ_ENUM_197
# define STREAMS_BOOST_PP_SEQ_ENUM_199(x) x, STREAMS_BOOST_PP_SEQ_ENUM_198
# define STREAMS_BOOST_PP_SEQ_ENUM_200(x) x, STREAMS_BOOST_PP_SEQ_ENUM_199
# define STREAMS_BOOST_PP_SEQ_ENUM_201(x) x, STREAMS_BOOST_PP_SEQ_ENUM_200
# define STREAMS_BOOST_PP_SEQ_ENUM_202(x) x, STREAMS_BOOST_PP_SEQ_ENUM_201
# define STREAMS_BOOST_PP_SEQ_ENUM_203(x) x, STREAMS_BOOST_PP_SEQ_ENUM_202
# define STREAMS_BOOST_PP_SEQ_ENUM_204(x) x, STREAMS_BOOST_PP_SEQ_ENUM_203
# define STREAMS_BOOST_PP_SEQ_ENUM_205(x) x, STREAMS_BOOST_PP_SEQ_ENUM_204
# define STREAMS_BOOST_PP_SEQ_ENUM_206(x) x, STREAMS_BOOST_PP_SEQ_ENUM_205
# define STREAMS_BOOST_PP_SEQ_ENUM_207(x) x, STREAMS_BOOST_PP_SEQ_ENUM_206
# define STREAMS_BOOST_PP_SEQ_ENUM_208(x) x, STREAMS_BOOST_PP_SEQ_ENUM_207
# define STREAMS_BOOST_PP_SEQ_ENUM_209(x) x, STREAMS_BOOST_PP_SEQ_ENUM_208
# define STREAMS_BOOST_PP_SEQ_ENUM_210(x) x, STREAMS_BOOST_PP_SEQ_ENUM_209
# define STREAMS_BOOST_PP_SEQ_ENUM_211(x) x, STREAMS_BOOST_PP_SEQ_ENUM_210
# define STREAMS_BOOST_PP_SEQ_ENUM_212(x) x, STREAMS_BOOST_PP_SEQ_ENUM_211
# define STREAMS_BOOST_PP_SEQ_ENUM_213(x) x, STREAMS_BOOST_PP_SEQ_ENUM_212
# define STREAMS_BOOST_PP_SEQ_ENUM_214(x) x, STREAMS_BOOST_PP_SEQ_ENUM_213
# define STREAMS_BOOST_PP_SEQ_ENUM_215(x) x, STREAMS_BOOST_PP_SEQ_ENUM_214
# define STREAMS_BOOST_PP_SEQ_ENUM_216(x) x, STREAMS_BOOST_PP_SEQ_ENUM_215
# define STREAMS_BOOST_PP_SEQ_ENUM_217(x) x, STREAMS_BOOST_PP_SEQ_ENUM_216
# define STREAMS_BOOST_PP_SEQ_ENUM_218(x) x, STREAMS_BOOST_PP_SEQ_ENUM_217
# define STREAMS_BOOST_PP_SEQ_ENUM_219(x) x, STREAMS_BOOST_PP_SEQ_ENUM_218
# define STREAMS_BOOST_PP_SEQ_ENUM_220(x) x, STREAMS_BOOST_PP_SEQ_ENUM_219
# define STREAMS_BOOST_PP_SEQ_ENUM_221(x) x, STREAMS_BOOST_PP_SEQ_ENUM_220
# define STREAMS_BOOST_PP_SEQ_ENUM_222(x) x, STREAMS_BOOST_PP_SEQ_ENUM_221
# define STREAMS_BOOST_PP_SEQ_ENUM_223(x) x, STREAMS_BOOST_PP_SEQ_ENUM_222
# define STREAMS_BOOST_PP_SEQ_ENUM_224(x) x, STREAMS_BOOST_PP_SEQ_ENUM_223
# define STREAMS_BOOST_PP_SEQ_ENUM_225(x) x, STREAMS_BOOST_PP_SEQ_ENUM_224
# define STREAMS_BOOST_PP_SEQ_ENUM_226(x) x, STREAMS_BOOST_PP_SEQ_ENUM_225
# define STREAMS_BOOST_PP_SEQ_ENUM_227(x) x, STREAMS_BOOST_PP_SEQ_ENUM_226
# define STREAMS_BOOST_PP_SEQ_ENUM_228(x) x, STREAMS_BOOST_PP_SEQ_ENUM_227
# define STREAMS_BOOST_PP_SEQ_ENUM_229(x) x, STREAMS_BOOST_PP_SEQ_ENUM_228
# define STREAMS_BOOST_PP_SEQ_ENUM_230(x) x, STREAMS_BOOST_PP_SEQ_ENUM_229
# define STREAMS_BOOST_PP_SEQ_ENUM_231(x) x, STREAMS_BOOST_PP_SEQ_ENUM_230
# define STREAMS_BOOST_PP_SEQ_ENUM_232(x) x, STREAMS_BOOST_PP_SEQ_ENUM_231
# define STREAMS_BOOST_PP_SEQ_ENUM_233(x) x, STREAMS_BOOST_PP_SEQ_ENUM_232
# define STREAMS_BOOST_PP_SEQ_ENUM_234(x) x, STREAMS_BOOST_PP_SEQ_ENUM_233
# define STREAMS_BOOST_PP_SEQ_ENUM_235(x) x, STREAMS_BOOST_PP_SEQ_ENUM_234
# define STREAMS_BOOST_PP_SEQ_ENUM_236(x) x, STREAMS_BOOST_PP_SEQ_ENUM_235
# define STREAMS_BOOST_PP_SEQ_ENUM_237(x) x, STREAMS_BOOST_PP_SEQ_ENUM_236
# define STREAMS_BOOST_PP_SEQ_ENUM_238(x) x, STREAMS_BOOST_PP_SEQ_ENUM_237
# define STREAMS_BOOST_PP_SEQ_ENUM_239(x) x, STREAMS_BOOST_PP_SEQ_ENUM_238
# define STREAMS_BOOST_PP_SEQ_ENUM_240(x) x, STREAMS_BOOST_PP_SEQ_ENUM_239
# define STREAMS_BOOST_PP_SEQ_ENUM_241(x) x, STREAMS_BOOST_PP_SEQ_ENUM_240
# define STREAMS_BOOST_PP_SEQ_ENUM_242(x) x, STREAMS_BOOST_PP_SEQ_ENUM_241
# define STREAMS_BOOST_PP_SEQ_ENUM_243(x) x, STREAMS_BOOST_PP_SEQ_ENUM_242
# define STREAMS_BOOST_PP_SEQ_ENUM_244(x) x, STREAMS_BOOST_PP_SEQ_ENUM_243
# define STREAMS_BOOST_PP_SEQ_ENUM_245(x) x, STREAMS_BOOST_PP_SEQ_ENUM_244
# define STREAMS_BOOST_PP_SEQ_ENUM_246(x) x, STREAMS_BOOST_PP_SEQ_ENUM_245
# define STREAMS_BOOST_PP_SEQ_ENUM_247(x) x, STREAMS_BOOST_PP_SEQ_ENUM_246
# define STREAMS_BOOST_PP_SEQ_ENUM_248(x) x, STREAMS_BOOST_PP_SEQ_ENUM_247
# define STREAMS_BOOST_PP_SEQ_ENUM_249(x) x, STREAMS_BOOST_PP_SEQ_ENUM_248
# define STREAMS_BOOST_PP_SEQ_ENUM_250(x) x, STREAMS_BOOST_PP_SEQ_ENUM_249
# define STREAMS_BOOST_PP_SEQ_ENUM_251(x) x, STREAMS_BOOST_PP_SEQ_ENUM_250
# define STREAMS_BOOST_PP_SEQ_ENUM_252(x) x, STREAMS_BOOST_PP_SEQ_ENUM_251
# define STREAMS_BOOST_PP_SEQ_ENUM_253(x) x, STREAMS_BOOST_PP_SEQ_ENUM_252
# define STREAMS_BOOST_PP_SEQ_ENUM_254(x) x, STREAMS_BOOST_PP_SEQ_ENUM_253
# define STREAMS_BOOST_PP_SEQ_ENUM_255(x) x, STREAMS_BOOST_PP_SEQ_ENUM_254
# define STREAMS_BOOST_PP_SEQ_ENUM_256(x) x, STREAMS_BOOST_PP_SEQ_ENUM_255
#
# endif
