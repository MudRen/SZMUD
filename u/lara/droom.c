// Code of ShenZhou
//wzfeng 99 11
//#include "room.h"

inherit ROOM;
int do_save(string arg);
void create()
{
        set("short", "С�᷿");
        set("long", @LONG
    ����һ�����쾫�ɣ���Ϊ������Ů�Թ뷿�����׷���һ����ױ̨������
�����˴�ҹ����õĸ�����֬ˮ�ۣ����ߵ��¼��Ϲ�����ȹ������һ��Ϊ�̱�
��֬ζƮ������һ��˵���������ܡ� 
LONG
        );
                      set("exits",([ 
                  "out" : __DIR__"zhengtang",

                ]));
        set("objects", ([
            __DIR__"npc/dfbb" : 1,
        ]));

        set("cost", 1);
	    set("invalid_startroom", 1);
        set("no_fight", "1");
		setup();
 
}

int()
{
	add_action("do_save",  "save");

}

int do_save(string arg)
{
        object me = this_player();
        tell_object(me, "�㲻���ڴ˴����̣�\n");
        return 1;
}
