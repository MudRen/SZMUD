// laoying.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "����Ӫ");
                  set("long",@long
��һ̤�����������һ����������ʮ��ͷ�۽��Ͷ�Ĵ�Ȯ���ֳ����ţ�
���ڵ��£�һ�������׺��õ�Ů������һ�Ż�Ƥ���ϣ���ִƤ�ޣ�
�ȵ�����ǰ�������ʺ���һͷ��Ȯ���ݶ�����վ��ǽ�ߵ�һ��
���ʺ���ҧȥ��
long);
                 set("exits",([
"out" : __DIR__"tingwai",
]));

set("objects",([
                __DIR__"npc/zjzhen" :  1,
]));
              setup();
              replace_program(ROOM);
}
