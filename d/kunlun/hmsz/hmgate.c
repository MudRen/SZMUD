// hmgate.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "����");
                  set("long",@long
��ǰ��һ����ׯԺ,��¥���Ǹߴ�,��������ϲ豭��С��ͭ���������⣬�Ŷ�
�Ҷ�д�š���÷ɽׯ���ĸ�������֣��ſ�վ�������Ҷ�,б�������ۣ���ݺ�
�ĵ����㡣
long);
                 set("exits",([
"west" : __DIR__"shanao1",
"enter" : __DIR__"hmttang",
]));

set("objects",([
                __DIR__"npc/jiading" :  2,
]));
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
