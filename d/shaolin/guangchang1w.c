// Code of ShenZhou
// Room: /d/shaolin/guangchang1w.c
// Date: CSWORD 96/02/28
// Added a back door for shaolin hh
// Apache 11/99
// modified by xiaojian Aug.23,2000: add a side door for tiaoshui job

#include <ansi.h>
inherit ROOM;
void init();
int do_jump(string);
int do_yong(string);

void create(){
        set("short", "�㳡");
        set("long", @LONG
������������ǰ�Ĺ㳡�������㳡�ɴ�����ʯ�̳ɣ���Ϊƽ̹���������
��Զ������Щ���𡣴Դ�С�ݴ�ʯ��ķ�϶�г��˳������㳡��Χ�������ܵ���
���֣��Ľ��ϸ����˼���ʯ�����ּ�����Ϊģ�����������˿�ľ��(mupai)����ǰ
����������վ�ż���ɮ�ˡ�
LONG
        );

        set("exits", ([
                "west" : __DIR__"shulin1",
                "southdown" : __DIR__"shijie11",
                "east" : __DIR__"guangchang1",
        ]));

        set("item_desc",([
                "mupai" :   "�����»������֣�Υ��������ɱ���⣡\n",
        ]));

        set("outdoors", "shaolin");

        set("objects",([
                CLASS_D("shaolin") + "/qing-wei" : 1,
        ]));
        set("cost", 1);
        setup();

}

void init() {
        add_action("do_jump", "jump");
                add_action("do_yong", "yong");
}

int valid_leave(object me, string dir) {
        if (!wizardp(me) && dir == "west" && me->query_skill("dodge",1) <= 20 
                && (present("qingwei biqiu", environment(me))))

        return notify_fail("��Ϊ��סȰ��: �����Ǳ��»������֣������н��޳���\n"
                    + RANK_D->query_respect(me) + "�Ṧ���ѣ�����ȿ���ľ�ƣ���Ҫ����ȥ��\n");

        return ::valid_leave(me, dir);
}

int do_jump(string arg) {
        object me = this_player();
        string event = NATURE_D->outdoor_room_event();
        
        if( !arg || arg == "" ) return 0;
        if( arg == "tree" ) {
                if (me->query("family/family_name") != "������" )
                        return 0;
                
                if (me->query("family/generation") > 37)
                        return 0;

        if (event != "event_night" && event != "event_midnight")
                        return notify_fail("�����ģ���ô�����ðɣ�\n");
                                         
                if (me->query_skill("dodge") < 200)
                        return notify_fail("�㡰ಡ���һ������������ֻ������һƬ��Ҷ��\n");
                        
                if (me->query("jingli") < 500 || me->query("neili") < 100)
                        return notify_fail("�������ĸ����飬����Ъһ����ɡ�\n");

                message("vision", 
                        me->name() + "һʽ���������ա����εض���������֦��һ��������Ӱ��ʧ��ããҹɫ�С�\n",
                        environment(me), ({me}) );
                write("��һʽ���������ա����εض���������֦��һ�������ѷ��������֡�\n");

                me->move("/d/shaolin/beilin2");

                message("vision", "��Ȼ���ꡱ��һ�����죬" + me->name() + 
                        "�Ӱ��������������\n", environment(me), ({me}) );
                write("����һʽ������˫�ɡ�������ط�����������\n");
                
                me->start_busy(1);
                return 1;
        }

}
   
int do_yong(string arg)
{
    
                object me,obj;
        string event = NATURE_D->outdoor_room_event();
        me= this_player();
                obj = present("shui tong", me);
        if( !arg || arg == "" ) return 0;
                if (arg != "һ�������Ϥ��������")
                        return notify_fail("���������ҽ�ʲô��\n");
                if (me->query("family/family_name") != "������" )
                        return 0;
                if (event != "event_night" && event != "event_midnight")
                        return notify_fail("�����������ţ�\n");
                if (!me->query("shaolin/job_asked")) 
                        return notify_fail("��û�������񣬲��ܴ������ȥ��\n");
                if (!obj)
                        return notify_fail("���ˮͰ�أ�\n");
        message_vision(HIC"$N�������洫���Ⱥ͵����������ȱ�����,�������ա���\n"NOR,me);
        message_vision(CYN"һλʦ�ְѲ��Ŵ�:����,ʦ�ܻ�������,���Ų���,����������ߡ���\n"NOR,me);
                message_vision("˵��,������$N����,��С��ת�˽�ȥ��\n",me);
                message("vision","С���漴�����ˡ�\n",environment(me),({me}) );
                me->move("/d/shaolin/houyuan");
                message("vision", me->name()+"�Ӳ���ֱ�����������ĺ�Ժ��\n",environment(me),({me}) );
                write("�����������ĺ�Ժ��\n");
                me->start_busy(1);
                return 1;
}
