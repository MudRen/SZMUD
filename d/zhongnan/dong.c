// road: /zhongnan/dong.c
// update by lara 01.10.23

inherit ROOM;

void create()
{
	set("short", "ɽ��");
 
    set("long",@LONG
����Сɽ�������һ��ǿ���ˮ���Ե����������γ�һ��С������
���⡣������ٽ�һ������Ļ����͵�Ҫ����ˮ���ˡ�����ɵ�С�ӱߡ�
�����ҪǱˮ(dive)�ˡ�
LONG);
	set("exits",([ "out" : __DIR__"river",
		]) );

	set("cost",2);
	setup();
}

void init()
{
    add_action("do_dive", "dive");
    add_action("do_dive", "qian");
}

int do_dive(string arg)
{
    object me = this_player();

    if (!arg || arg=="") return 0;

    if ( arg == "river" || arg == "water") 
	{
		message_vision("$Nһ��������ˮ��......", me);

        if (me->query_skill("yunu-xinjing",1)<60 )
	 	{
			message_vision("��ϧ$N��ˮ�������˰���ʲôҲû������ֻ�����ذ��ϡ�\n", me);
        }
        else {
			message("vision", "\n\n", environment(me));
         //   message("vision","����ˮ��Ǳ�У����������ȥ......\n\n\n", environment(me));
            message_vision("$N��ˮ��Ǳ�У����������ȥ......\n\n\n", me);
            me->move("/d/gumu/water2");
        }
        return 1;
	}
	
	return 0;
}
