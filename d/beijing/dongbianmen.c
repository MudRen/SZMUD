//Cracked by Roath
// Room: /d/beijing/dongbianmen.c

inherit ROOM;

string GATE_DESC_SHORT="������";
string GATE_DESC_LONG=@LONG
���Ǿ������Ůǽ�������ƫ�ţ��˴���ǽ�����������
���ĳ�ǽҪ�Ͱ�һЩ���ؾ�Ҳ���٣��̲�Ҳ���������������
ô�������ߴ��ŵĴ������ˮ������ٳּ�ҵ֮�ˡ����űߵ�
��ʾ(gaoshi)��մ���˻ҳ���
LONG;

mapping GATE_EXITS=([
   "north" : __DIR__"tulu_dongbian_n",
   "south" : __DIR__"tulu_dongbian_s",
   "west"  : __DIR__"chongwenmen",
]);

mapping GATE_OBJECTS=([
    __DIR__"npc/bj_bing":2,
]);

string GATE_ENTER_DIR="west";
#include "outer_gate.h"
