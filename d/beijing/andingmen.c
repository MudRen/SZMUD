//Cracked by Roath
// Room: /d/beijing/andingmen.c

inherit ROOM;
string GATE_DESC_SHORT="������";
string GATE_DESC_LONG=@LONG
���Ǿ��������İ����š������ǵ�ʤ�ţ��ϱ���ȥ��¥�Ĵ����
����Զ�����У�ֻ��Щ��ũ�����˲˽��������ſڵĸ�ʾ(gaoshi)
�ƺ�Ҳûʲô�˿���
LONG;
mapping GATE_EXITS=([ /* sizeof() == 2 */
  	"south" : __DIR__"zhonglou",
  	"west"  : __DIR__"tulu_anding_w",
        "east"  : __DIR__"tulu_anding_e",
	]);
mapping GATE_OBJECTS=([
    __DIR__"npc/bj_bing":3,
]);

string GATE_ENTER_DIR="south";

#include "outer_gate.h"
