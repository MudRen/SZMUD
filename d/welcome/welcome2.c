// welcome.c
// modified by lisser, 10/4/2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", HIC"����"NOR);
        set ("long", "�����Ǵ������������й���һ����⣬����"HIW"�����ݡ�"NOR"�����ڰ�
��ȫ�ǵ��ξ�ϸ�ļҾߣ�����������ʯ�����Σ������ԳƸ�������ʯԲ��
���Σ������ǽ���Ϲ���һ����ͼ��map������������ݣ��������ӻ��꣬
�����������⡣�������������Ϥһ�»��������
");
        set("item_desc", ([
                "map" : HIG+"

                  ************************
	              ��ӭ���١����ݡ�
                  ************************\n"+NOR+"

                    ˯�� �� ���
                             �� 
                    �ӻ����������������\n\n",
        ]));

	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"welcome3",
		"west" : __DIR__"welcome4",
		"north" : __DIR__"welcome5",
		"down" :"/d/city/kedian",
		]));

	set("valid_startroom", "1");
	set("no_fight", 1);

setup();
}

int valid_leave(object me, string dir)
{
	me = this_player();

	if( dir=="enter" ) return 1;

	if( dir=="down" ) {
		me->delete("newbie", "yes");
	}
	return ::valid_leave(me, dir);
}