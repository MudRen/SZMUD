//Cracked by Roath
// Room: /d/beijing/youanmen.c

inherit ROOM;

string GATE_DESC_SHORT = "�Ұ���";
string GATE_DESC_LONG = @LONG
�����Ǿ��������֮һ�����ھ��뷱���ضνϽ������ƺ����ô����������
�����ŵ�˵��ģ�������������������ͨ�������ź͹㰲�ŵ���·��ԶԶ������
����һЩũ����������ս�Ȼ��ͬ������������һ�Ÿ�ʾ (gaoshi)��
LONG;
mapping GATE_EXITS=([ /* sizeof() == 2 */
  "north" : __DIR__"youandajie",
  "east"  : __DIR__"tulu_youan_e",
  "west"  : __DIR__"tulu_youan_w",
]);
mapping GATE_OBJECTS=([
	__DIR__"npc/bj_bing":2,
]);

string GATE_ENTER_DIR="north";
#include "outer_gate.h"

