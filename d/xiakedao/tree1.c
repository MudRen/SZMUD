//Cracked by Roath
// xiakedao/tree1.c
// Ssy 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "����");
        set("long", @LONG
���������¸����������һ�����š�ɳ̲����Լ�ɼ�����С��
�㣬��ֻ��������ͷ�����ŵػ��衣������ȥ��ֻ������һɫ������
��ϴ�������Ļ��󳩡�
    ����Χ�ƺ�����һЩҰ��(guo)��
LONG );
        set("item_desc",([
			  "guo" : "�����޵�Ұ������֪�ܲ���ժ������\n",
        ]));

	set("outdoors", "xiakedao" );
	set("cost", 2);
	set("guocount",5);
	setup();
}

void init()
{
  ::init();

        add_action("do_zhai", "zhai");
        add_action("do_pa", "pa");
        add_action("do_pa", "climb");

}

int do_zhai(string arg)
{
        object ob;
        object me = this_player();

	if (present("ye guo", me))
	  {
	    message("vision","���˻���Ҫ����\n",me);
	    return 1;
	  }
	
	message_vision("$N������ժ����һöҰ����\n",me);
	if (query("guocount")>0)
	  {
	    ob=new(__DIR__"obj/guo1");
	    ob->move(me);
	    add("guocount", -1);
	  }
	else
	  {
            ob=new(__DIR__"obj/guo2");
            ob->move(me);
	  }
       return 1;
}

int do_pa(string arg)
{
        object me = this_player();

        if ( !arg )
                return notify_fail("��Ҫ���Ķ�����\n");
        if ( arg != "down" )
                return notify_fail("ʲ�᣿\n");
        message_vision("$N���ֱ��ŵ�������ȥ��\n",me);
        me->move(__DIR__"shanding");  
        message_vision("$N����������������\n",me);
        return 1;
}

