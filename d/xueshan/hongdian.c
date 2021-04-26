// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�����Ǵ����µĺ����ڹ��߰��������ϻ���ɫ���������й�
���ܼ���ա�������棬�����ڣ��������������δ󻷣������㣬��
�ų�ȹ���������������ۣ�������ӵ�������������۷��������ִ��
�������������ۣ����������ӵ�����������ᡣ�����(zuo)����
ʯ��������ʯ�񻨡�̫ƽ����ʮ�ֻ���
LONG
        );
        set("exits", ([
                "southdown" : __DIR__"zoulang",
        ]));
	set("item_desc", ([
		"zuo" :
	"������߸����ϡ�\n",
        ]) );

	set("cost", 1);
        setup();
}
void init()
{
        add_action("do_jump", "jump");
}


int do_jump(string arg)
{
	object me;
        me = this_player();

        if( !arg || arg=="" )
                return 0;
        if( arg=="zuo")
        {
                if (me->query_skill("dodge") < 30){
                    write("����ͼ���Ͻ�������������������ݣ�ֻ�����ա�\n");
		return 1;
		}
                else {
                    write("������Ծ���˽������\n");
                    message("vision",
                             me->name() + "һ����Ծ���˽������\n",
                             environment(me), ({me}) );
                    me->move(__DIR__"zuo");
                    message("vision",
                             me->name() + "������Ծ��������\n",
                             environment(me), ({me}) );
                return 1;
	 }
     }
}

int valid_leave(object me, string dir)
{
        return ::valid_leave(me, dir);
}
