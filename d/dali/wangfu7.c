// Code of ShenZhou
// Room: /d/dali/wangfu7.c

inherit ROOM;

void create()
{
	set("short", "�й��");
	set("long", @LONG
����һ��ʯ�ڣ�������о���Ϸ��ͼ������������צ����̬
������ͬ����������𣬸�һ�����ף���һ��������̶��ɡ�
����һֻ���룬ֱ��һ�����ף���һ��������̶��ɡ������
�к��������ޡ�
LONG
	);
	set("cost", 1);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wangfu4.c",
]));
	set("no_clean_up", 0);
set("wangfu", 1);

	setup();
}

void init()
{
        add_action("do_climb", "climb");
}


int do_climb(string arg)
{
        object me;

        me = this_player();

        if ( !arg || ( arg != "wall" ) )
                return notify_fail("ʲô��\n");
	if ( (int)me->query("neili") < 100)
	return notify_fail ("��������ǽ����ȥ�������ֽ�������������ȥ��\n");

               if ( (int)me->query("combat_exp") <15000)
	{
	me->receive_damage("qi", 50, "��ǽ�Ϲ�������ˤ����");
                me->receive_wound("qi",  50, "��ǽ�Ϲ�������ˤ����");
                message_vision("$Nֻ��������һ�ɣ�... 
��...��\n", me);
                tell_object(me, 
"���ǽ�Ϲ���������ֻ���û����޴����ۣ������˼����ˡ�\n");
                message("vision", "ֻ��" + me->query("name") + 
"��ǽ�Ϲ�µµ�ع������������ڵ��ϰ�������������\n", environment(me), me);
return 1;
        }

	 me->add("jingli", (-1)*random(50), "������֧����");
	 me->add("neili", (-1)*random(50));
		
	message_vision("$N�����ֽŲ��õ����ձ�����ȥ��\n", me);

        switch( random(3) ) 
        {
            case 0:
                if ( (int)me->query_skill("finger", 1) < 100)
                {
                        me->improve_skill("finger", me->query("str"));
                        
write("���ֽŲ��õ�����һ��ǽ���ƺ�����ָ����Щ���ۡ�\n");
                        me->set_temp("wall_climbed",1);
                }
            case 1:
                if ( (int)me->query_skill("force", 1) < 100)
                {
                        me->improve_skill("force", me->query("con"));
                        
write("���ֽŲ��õ�����һ��ǽ���ƺ�����������Щ������\n");
                        me->set_temp("wall_climbed",1);
                }
            case 2:
                if ( (int)me->query_skill("dodge", 1) < 100)
                {
                        me->improve_skill("dodge", me->query("dex"));
                        
write("���ֽŲ��õ�����һ��ǽ���ƺ������ж������Щ��\n");
                        me->set_temp("wall_climbed",1);
                }
}
       if ( !me->query_temp("wall_climbed") )
        {
                
write("����������������Ѵ���֮����\n");
        }
        return 1;
}











