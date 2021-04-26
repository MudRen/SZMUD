// Code of ShenZhou
// ROOM/d/murong/chufang.c
// arthurgu 1999.9

inherit ROOM;

int serve();

void create()
{
        set("short", "����");
        set("long", @LONG
������Ľ���ϼҵĳ�����רΪס����������ſ��ṩ��ʳ(serve)��
Ľ�����ȱ�Ϊ����,���Լ�ʹ�������ǵĻ�ʳ��Ҳ��Ϊ���¡������
����������á�
LONG
        );

        set("exits", ([
                "east" : __DIR__"qing3",
        ]));
        
        setup();
}

void init()
{
       object ob=this_player();

        if (userp(ob) && !wizardp(ob) && ob->query("family/family_name") != "����Ľ��") {
                message_vision("���Ӻȵ�����$N�㲻����Ľ�ݼҵ��ˣ���ô�����������ˣ���ȥ��\n",ob);
                remove_call_out("kickout");
                call_out("kickout", 1, ob);
        }

        add_action("do_serve", "serve");
}

int kickout(object ob)
{
        if (!present(ob,find_object("/d/murong/chufang.c"))) {
                return 1;
        }
        message_vision("���Ӱ�$N���˳�ȥ��\n",ob);
        ob->move("/d/murong/qing1");
        message("vision","ֻ����"+ob->query("name")+"���������ش��������˳�����\n", environment(ob), ob);
        return 1;
}

int do_serve()
{
        object ob,me;
        me=this_player();

        message_vision("$N�����ҪЩʳ��Ժȡ�\n", me);

        if (!present("songzi gao", environment(me))
                && !present("feicui tianbing", environment(me))
                && !present("oufen", environment(me))
                && !present("songzi gao", me)
                && !present("feicui tianbing", me)
                && !present("oufen", me))
        {
                switch(random(3)) {
                case 0:
                        ob=new("/d/murong/obj/tianbing");
                        break;
                case 1:
                        ob=new("/d/murong/obj/gao");
                        break;
                case 2:
                        ob=new("/d/murong/obj/oufen");
                        break;
                }    
                ob->move(environment(me));
                message_vision("���Ӷ˳�"+ob->name()+"��$N�����������ԣ��������С���\n", me);
        }
        else message_vision("���Ӷ�$N˵��������ô�ڣ�����û�����ء�\n", me);
        
        if (!present("biluochun", environment(me))
                && !present("ling1", environment(me))
                && !present("ling2", environment(me))
                && !present("biluochun", me)
                && !present("ling1", me)
                && !present("ling2", me)) {
                switch(random(3)) {
                case 0:
                        ob=new("/d/murong/obj/biluochun");
                        break;
                case 1:
                        ob=new("/d/murong/obj/ling1");
                        break;
                case 2:
                        ob=new("/d/murong/obj/ling2");
                        break;
                }
                ob->move(environment(me));
                message_vision("���Ӷ˳�"+ob->name()+"��$N�����������ȣ��������С���\n", me);
        }
        else message_vision("���Ӷ�$N˵�����㻹û�����أ�������˵�ɡ�\n", me);
        return 1;
}

int valid_leave(object me, string dir)
{
        if (present("songzi gao", me)
                || present("feicui tianbing", me)
                || present("oufen", me)
                || present("biluochun", me)
                || present("ling1", me)
                || present("ling2", me))
                return notify_fail("����������˵���������ǳ������߰ɡ���\n");
        return ::valid_leave(me, dir);
}
