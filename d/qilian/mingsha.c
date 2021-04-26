// Code of ShenZhou
#include "room.h"
inherit ROOM;
void create()
{
  set ("short", "��ɳɽ");
  set ("long", @LONG
��ɳɽʵ���ϲ�����һ��ɽ��������Դ������ɽ���ĳ�Ӵ�����
��ʯ��ɳ���ѻ����ɵ�һ��Сɳ��΢�紵����ɳɽ�������˵�������
�ʶ������˳�֮Ϊ��ɳɽ��ɳ�����ƺ���һ�ֳ������䶯����Ϧ����
̧ͷ������ֻ��������Σɽ(mountain)���Ͻ�����䡣��˵��������
��ʦ���������˾������º�Ը������ɳɽ���ڶϲ��Ͽ����˵�һ��ʯ
�ߡ�
LONG);

  set("item_desc", ([ 
  "mountain" : "��Σɽ�ǰ�ʴ��ɽ��ɽ���޲�ľ��ɽʯ��֣��ں�ʯӢ����ĸ��\n"
               "̫�����䣬�����ճ���⡣\n",
]));
  set("outdoors", "/d/qilian");
  set("exits", ([ 
  "east" : __DIR__"sulew",
  "westup" : __DIR__"drukou",
]));
  set("objects", ([
               "/d/xingxiu/npc/shachong" : 1 ]));
	set("cost", 3);
  setup();
  replace_program(ROOM);
}

