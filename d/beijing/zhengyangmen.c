//Cracked by Roath
// Room: /d/beijing/zhengyangmen.c

inherit ROOM;

string GATE_DESC_SHORT = "������";
string GATE_DESC_LONG = @LONG
�������Ǿ����ڳǾŴ������������֮һ���������Ϳ����Ͻ�
���ˡ�������ȥ�Ĵ��Ǿ���ҪԱ���ϰ���ż��·���Ķ����ϼӲ�
�ʡ��ű��ϵĸ�ʾ (gaoshi) �ƺ�д��Щʲô��
LONG;
mapping GATE_EXITS=([ /* sizeof() == 3 */
  "south" : __DIR__"zhengyangdajie",
  "north" : __DIR__"changanjie",
]);

mapping GATE_OBJECTS=([
  __DIR__"npc/bj_bing":4,
]);

#include "inner_gate.h"

