#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIB"��ɽ���ſ�ջ"NOR);
        set("long", @LONG
�˴������������������������֮����ʥ�أ�������С������,
��ȥ����������˿��֮·֮�ؾ�֮·,�ʴ���������Ҳ��Ϊ�ڶ࣬��
����������Ϊ�����˿������ֻ࣬�������10��䣬����һ��������
ռ�ؿ��꣬����ȴ������棬�������߳�͢�����ģ������������س�
��......
LONG
        );

//      set("no_fight", 1);
        set("exits",([
                 "fun": "/u/knpc/dilao.c",
                 "gm": "/d/gumu/fengfang.c",
                 "xx" : "/d/xingxiu/xiaoyao.c",
                 "yz" : "/d/city/kedian.c",
                 "thd" : "/d/taohua/hyjuchu.c",
                 "xixia" : "/d/xixia/center.c",
        ]));

              set("objects", ([ 
                   "/u/knpc/npc/zhanggui.c" : 1, 
                   "/u/knpc/npc/dashou.c":2,
                ]));
        set("cost", 0);
        setup();
    
       call_other("/clone/board/knpc_b", "???")
;
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i;
        inv = all_inventory(me);
        if ( dir == "out" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("���ʲô������մ���ͯ������\n");
                }
        }

        return ::valid_leave(me, dir);
}
