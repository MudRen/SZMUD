//Cracked by Roath
// Room: /d/beijing/west/yonganmen.c

inherit ROOM;

string GATE_DESC_SHORT = "������";
string GATE_DESC_LONG = @LONG
���Ǿ���������Ż������Ϸ�������Ͼ������Ƕ��������ǡ�
������������Ǻ��ϵģ����ű����������Χ�ſ���ʾ (gaoshi)��
���ߵ���·ͨ�����ź��Ұ��š�
LONG;
mapping GATE_EXITS=([ /* sizeof() == 3 */
  "east"  : __DIR__"tulu_yongan_e",
  "west"  : __DIR__"tulu_yongan_w",
  "north" : __DIR__"shizilukou",
  "south" : __DIR__"dadao_yongan_s",
]);

mapping GATE_OBJECTS=([
	__DIR__"npc/bj_bing":4,
]);

string GATE_ENTER_DIR="north";
#include "outer_gate.h"
