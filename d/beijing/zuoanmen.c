//Cracked by Roath
// Room: /d/beijing/zuoanmen.c

inherit ROOM;

string GATE_DESC_SHORT = "����";
string GATE_DESC_LONG = @LONG
���Ǿ��������ƫ�ţ����ǵĶ��Ǹϼ��İ��գ�ż����Щ��
·�����ű����������Χ�ſ���ʾ (gaoshi)�����ߵ���·ͨ������
�ź͹����š�
LONG;
mapping GATE_EXITS=([ /* sizeof() == 3 */
  "east"  : __DIR__"tulu_zuoan_e",
  "west"  : __DIR__"tulu_zuoan_w",
  "north" : __DIR__"chongwendajie",
]);

mapping GATE_OBJECTS=([
	__DIR__"npc/bj_bing":4,
]);

string GATE_ENTER_DIR="north";
#include "outer_gate.h"
