//Cracked by Roath
// room: /d/xingxiu/btbarn
// Jay 10/8/96

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���ǰ���ɽׯ�����ᡣ���ﵽ���Ƕ��ߣ�ǽ����һ�š��߾���(shejing)��
LONG
        );
        set("exits", ([ 
                          "south" : __DIR__"road1",
                        "west" : __DIR__"barn2a",
        ]));

	create_door("west", "ľ��", "east");

	set("item_desc", ([
		"shejing" : "����ɽѵ���ܷ����ɽ����߱�(bian)�����ȣ�\n"
			"�����Ȼ��˿�ʹ���ж���Ҳ���԰����ȱ�ض��ߣ����Ժ��ˡ�\n"
			"��ʮ������Ԧ�����������£�Խ�߳ɹ���Խ�ߡ�\n",
	]));
        set("objects", ([ 
	    __DIR__"npc/snake" : 3,
         ]) );
//        replace_program(ROOM);
	set("cost", 0);
        setup();
}


void init()
{
   add_action("do_lingwu","lingwu");
}
                
int do_lingwu(string arg)                
{
   object me = this_player();
   int level, check;

   if (!arg || arg!="shejing") {
        write("��Ҫ����ʲô��\n");
        return 1;
   }
   level = (int)me->query_skill("poison",1);
   check = level*level*level;
   
   if (!me->query("family") || me->query("family/family_name") != "����ɽ") {
	write("����δ����գ�������վ���\n");
        return 1;
   }

   if ( level < 30) {
        write("�������Զ�����ڸ�����޷�����\n");
        return 1;
   }
   if ( level > 60) {
        write("�������Զ���̫ǳ��û���κΰ�����\n");
        return 1;
   }
   if (check > (int)me->query("combat_exp")*10 ) {
        write("��ʵս���鲻�㣬�޷�����\n");
        return 1;
   }
   if ( (int)me->query("jing") < 30 ) {
      write("�㾫���޷����С�\n");
        return 1;
   }
   me->receive_damage("jing", 20);
   me->improve_skill("poison", me->query("int"));
   write("�������߾���������ʩ���ķ��š�\n");
   return 1;
}


