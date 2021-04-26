//room: changl8.c
/*Updated by George	98/7
	1. if dodge<30 add dodge
	2. if dodge>30 && yueying-wubu<30 add yueying-wubu
*/

inherit ROOM;

void init();
int do_dancing();

void create()
{
  set("short","����");
  set("long",@LONG
����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ�Ƴɣ�����
������������ͼ��(hua)���������ɣ�����ʤ�գ��ƺ���𴦲�ͬ����
�岻֪����ʲô�������ģ��������������Ϣ����ֻ�е���������ģ�
�ǳ����������ͨ�������
LONG
    );

  set("item_desc",([
	  "hua"	:	"����һ��������������Ůͼ��������Ů����������(dancing)��\n",])
	 );
  set("exits",([
      "west" : __DIR__"changl15",
      "east" : __DIR__"changl4",
     ]));

 setup();
//replace_program(ROOM);
}

void init()
{
	add_action("do_dancing", "dancing");
}

int do_dancing()
{
	mapping fam; 
	object ob;

	ob = this_player();
	
	if (!(fam = ob->query("family")) || fam["family_name"] != "���չ�")
	{
		write("������������ˣ��㿴�ſ��Ž���ס��֮��������\n");
		return 1;
	}

	if ((int)ob->query_skill("dodge", 1) < 30) 
    {
			
		if( (int)ob->query_skill("dodge", 1)* (int)ob->query_skill("dodge", 1) * (int)ob->query_skill("dodge", 1)/ 10 > (int)ob->query("combat_exp") ) {
			write("Ҳ����ȱ��ʵս���飬��Ի��е��⾳�����޷���ᡣ\n");
			return 1;
		}
		ob->receive_damage("jing", 10);
		ob->improve_skill("dodge", ob->query("int"));
		write("������������ˣ��㿴�ſ��Ž���ס��֮��������\n");
		return 1;
	}
	else if((int)ob->query_skill("yueying-wubu",1)>30)
	{
		write("������������ˣ��㿴�ſ��Ž���ס��֮��������\n");
		return 1;
	}
	else{
		ob->receive_damage("jing",10);
		ob->improve_skill("yueying-wubu",ob->query("int"));
		write("������������ˣ��㿴�ſ��Ž���ס��֮��������\n");
		return 1;

	}

	return 1;
}