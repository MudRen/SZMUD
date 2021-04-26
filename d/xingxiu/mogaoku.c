// Code of ShenZhou
// /d/xingxiu/mogaoku.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����ǽ���ϻ�����������صĻ��棬����Ů���죬�������ã����޺�
����ͼ(tu)���㱻��Щ�������Ļ�֮�������ˡ�
LONG
        );
        set("exits", ([ 
             "out" : "/d/qilian/yueerquan",
	     "east" : "/d/qilian/dtongdao5",
	]));
	set("item_desc", ([
		"tu" : "ͼ�ϻ���һ���޺����ֳ��ƣ����ְ�סһֻ����ͻ���\n",
	]));

	set("cost", 1);
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

   if (!arg || arg!="tu") {
	write("��Ҫ����ʲô��\n");
	return 1;
   }
   level = (int)me->query_skill("training",1);
   check = level*level*level;
   
   if ( level < 30) {
	write("ͼ�����������ڸ�����޷�����\n");
        return 1;
   }
   if ( level > 100) {
        write("ͼ���������̫ǳ��û���κΰ�����\n");
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
   me->improve_skill("training", me->query("int"));
   write("��Ȼ���ͼ���޺������ӣ�������Ԧ�����ľ��衣\n");
   return 1;
}


