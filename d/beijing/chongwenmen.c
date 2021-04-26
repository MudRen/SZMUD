//Cracked by Roath
// Room: /d/beijing/chongwenmen.c

inherit ROOM;

string GATE_DESC_SHORT = "������";
string GATE_DESC_LONG = @LONG
�������Ǿ����ڳǾŴ������������֮һ���������Ϳ����Ͻ�
���ˡ�������ȥ�Ĵ��Ǿ���ҪԱ���ϰ���ż��·���Ķ����ϼӲ�
�ʡ��ű��ϵĸ�ʾ (gaoshi) �ƺ�д��Щʲô��
LONG;
mapping GATE_EXITS_NIGHT=([ /* sizeof() == 3 */
  "north" : __DIR__"wangfudajie",
  "south" : __DIR__"chongwendajie",
  "west"  : __DIR__"changanjie_e",
]);
mapping GATE_EXITS=([ /* sizeof() == 3 */
  "north" : __DIR__"wangfudajie",
  "south" : __DIR__"chongwendajie",
  "east"  : __DIR__"dongbianmen",
  "west"  : __DIR__"changanjie_e",
]);
mapping GATE_OBJECTS=([
  __DIR__"npc/bj_bing":4,
]);

int fix_exits_for_night(int is_night) {
    if (is_night) {
	set("exits", GATE_EXITS_NIGHT);
    }else{
	set("exits", GATE_EXITS);
    }
}
#include "inner_gate.h"
