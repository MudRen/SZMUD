// Code of ShenZhou
// houyuan.c ������Ժ
//Jay 2/3/97

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����Ǻ��ָ��ĺ�Ժ��Ժ�������˲��ٵĸ����滨��ݣ���֪����ʲôԭ��
���������Ը�ɫ�ջ�Ϊ�ࡣԺ����Ѿ�ߵķ��䣬������һ����(men)���躲������
Ժ��������
LONG
        );
        set("item_desc", ([
                "men" : "�����ź������С��Ĺ뷿��\n",
        ]));

        set("exits", ([
                "east" : __DIR__"dongxiang",
                "south" : __DIR__"dayuan1",
                "west" : __DIR__"xixiang",
        ]));
        set("objects", ([
                __DIR__"npc/tuisi" : 1,
        ]));

        set("cost", 0);
        setup();
}

void init()
{
        add_action("do_unlock", "unlock");
        if (present("ling tuisi", environment(this_player())))
                delete("exits/east");
}
int do_unlock(string arg)
{
        object ob;
        if (query("exits/east"))
                return notify_fail("�������Ѿ��Ǵ򿪵ġ�\n");
        if (!arg || (arg != "men" && arg != "east"))
                return notify_fail("��Ҫ��ʲô��\n");
        if (!(ob = present("guifang key", this_player())))
                return notify_fail("�㲻��������\n");
        set("exits/east", __DIR__"dongxiang");
        message_vision("$N��һ��Կ�״򿪷��ţ�����Կ��ȴ���ˡ�\n", this_player());
        destruct(ob);
        return 1;
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("ling tuisi", environment(me))) && 
                (dir == "west" || dir =="east"))
                return notify_fail("�躲�ֵ�ס���㣺��������լ��\n");
        return ::valid_leave(me, dir);
}
