// Code of ShenZhou

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���п���һ�ֻ�б�����һ������ת����ͼ(picture)���������
�м�յ���͵ƣ����Ź���Ļƹ⣬����ڼ����һ�����������ռ�ָ�
����ڤ���硣����΢΢�ζ�������֨֨�����졣
LONG
	);

	set("exits", ([
		"east" : __DIR__"houyuan",
	]));
	set("item_desc", ([
                "picture" : "���������������ϣ��ֽ�ת��ӡ�������з��ֺ�˫¹����ʾ¹ҰԷ˵������\n"
			    "�Ļ��ǣ���������ʣ���·�����ڱ������������߹�����������˵����\n",
        ]));
	setup();
}

void init()
{
	add_action("do_enter", "enter");
}

int do_enter(string arg)
{
	object me=this_player();

	if( !arg || arg=="" ) return 0;

	if ( me->query_skill("lamaism", 1) < 150) return 0;

	if ( arg == "picture" ) {
	tell_object(me, "�㳯�ڻ���ȥ��\n");
	message("vision",
                        me->name() + "��ƮƮ�س��ڻ���ȥ����Ӱ����û�ڱڻ����ˡ�\n",
                        environment(me), ({me}) );
                me->move("/d/xueshan/wangyou");
                message("vision",
                        me->name() + "���������˽�����\n",
                        environment(me), ({me}) );
                return 1;
        }
}
