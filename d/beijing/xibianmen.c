//Cracked by Roath
// Room: /d/beijing/xibianmen.c

inherit ROOM;

string GATE_DESC_SHORT = "������";
string GATE_DESC_LONG = @LONG
���Ǿ������Ůǽ�������ƫ�ţ��˴���ǽ�����������
���ĳ�ǽҪ�Ͱ�һЩ���ؾ�Ҳ���٣��̲�Ҳ���������������
ô�������ߴ��ŵĴ������ˮ������ٳּ�ҵ֮�ˡ��ſڵĸ�
ʾ(gaoshi)���Ѿ�մ������๸.
LONG;
mapping GATE_EXITS=([ /* sizeof() == 3 */
  "south" : __DIR__"tulu_xibian_s",
  "north" : __DIR__"tulu_xibian_n",
  "east"  : __DIR__"xuanwumen",
]);
 
mapping GATE_OBJECTS=([
        __DIR__"npc/bj_bing":2,
]);

string GATE_ENTER_DIR="east";
#include "outer_gate.h"
