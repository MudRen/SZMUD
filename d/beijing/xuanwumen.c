//Cracked by Roath
// Room: /d/beijing/xuanwumen.c

inherit ROOM;

string GATE_DESC_SHORT = "������";
string GATE_DESC_LONG = @LONG
��������ͨ���пڣ����ţ����ﳤ���ֵĽ�ͨҪ���������������ϰ��ն���
�ϼӲ��ʡ����ϵĸ�ʾ (gaoshi) �ƺ�д��Щʲô��
LONG;
mapping GATE_EXITS_NIGHT=([ /* sizeof() == 3 */
  // "north" : "/d/beijing/zijin/tianansquare",
  "east" : __DIR__"changanjie_w",
  "south" : __DIR__"xuanwudajie",
  "north" : __DIR__"fuchengdajie_s",
]);
mapping GATE_EXITS=([ /* sizeof() == 3 */
  // "north" : "/d/beijing/zijin/tianansquare",
  "west" : __DIR__"xibianmen",
  "east" : __DIR__"changanjie_w",
  "south" : __DIR__"xuanwudajie",
  "north" : __DIR__"fuchengdajie_s",
]);

mapping GATE_OBJECTS=([
  __DIR__"npc/bj_bing":4,
]);

void fix_exits_for_night(int is_night)
{
  if (is_night) {
    set("exits", GATE_EXITS_NIGHT);
  }else{
    set("exits", GATE_EXITS);
  }
}

#include "inner_gate.h"
