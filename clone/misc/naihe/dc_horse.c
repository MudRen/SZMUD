//                ��׼��������ʾ��                                   |
// ���ڹһ����˿�����Ϸ�ķ��䣬����  ��dc_horse.c
// by naihe  2002-04-23  ��ï��
// �������Ը��ı��ļ�Դ�룬лл��

#include <ansi.h>
inherit ROOM;

int t_time,t_gold;

void create()
{
	set("short", HIR"����"NOR);
	set("long", "������һ�����������úʹ�����࣬����������һ��Χ��Ȧ�ӵ�ʯ���ˣ�
������һ�����ģ���Ļ�����������ߵ�ǽ��������һ�Ŵ���ֽ������д����
�����֣���˵������shuoming�����������߻��м���ʯ�����ɵ����ӡ�\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("invalid_startroom",1);

	set("item_desc",([
	    "shuoming":"������ask ������ about all �ɻ����ر�����Ϣ����\n",
	    "˵��":"������ask ������ about all �ɻ����ر�����Ϣ����\n",
	]));

	set("objects", ([
	    __DIR__"obj/yizi" : 1,
	    ]));

	set("exits", ([
	    "west" : __DIR__"dc_dating",
	    ]));

	setup();
}

void init()
{
        if (wizardp(this_player()))  add_action("do_xxx", "xxx"); // wiz ���Բ�ѯ��ֵ��
	add_action("do_skills",  "exercise");
	add_action("do_skills",  "dazuo");
	add_action("do_skills",  "respirate");
	add_action("do_skills",  "tuna");
	add_action("do_skills",  "practice");
	add_action("do_skills",  "lian");
	add_action("do_study",  "study");
	add_action("do_study",  "du");
	add_action("do_gmmn",  "gmmn");
	add_action("do_sumn", "sumn");
	add_action("do_food", "eat");
	add_action("do_food", "chi");
	add_action("do_food", "drink");
        add_action("do_food", "he");
}

  void reset() 
  { 
                ::reset(); 
                set("no_clean_up", 1); 
  } 

int do_xxx()
{
     	write("�ܵ������������"+t_time+ "��  ����֧���㣺"+t_gold+"  ��\n");
	return 1;
}

int do_food(string arg)
{
	tell_object(this_player(), "�Ժ��뵽��¥������\n");
	return 1;
}

int do_skills(string arg)
{
	tell_object(this_player(), "С���н��˼������߻���ħ��\n");
	return 1;
}

int do_study(string arg)
{
	tell_object(this_player(), "��������飿������ý�ȥ�𡭡�\n");
	return 1;
}

int do_gmmn(string arg)
{
	object qian,me,mygold,nowqian;
	me = this_player();
	qian = present("gold_money", me);
	nowqian = new("/clone/money/gold");
	nowqian->set_amount(200);

	if (me->query("id") == "szrobot")
	{
	if((int)qian->query_amount() > 299) return notify_fail("����ô��Ǯ��������㰡�û����ˣ�\n");

	nowqian->move(me);
	tell_object(me,"ok,�����200GOLD��\n");
	t_time++;
	t_gold-=200;

//		log_file("DUCHANG", sprintf("%s(%s)��%s��������ȡ200���ƽ𡣣�lost��\n",
//		me->query("name"), getuid(me), ctime(time())));

	return 1;
	}

	else
	return 0;
}

int do_sumn(string arg)
{
	object qian,me;
	me = this_player();
	if (me->query("id") == "szrobot")
	{
	qian = present("gold_money", me);

	if((int)qian->query_amount() < 300) return notify_fail("Ǯ����������ʡ�Űɣ��û����ˣ�\n");

	qian->add_amount(-200);
	tell_object(me,"ok,������200GOLD��\n");
	t_time++;
	t_gold+=200;
//		log_file("DUCHANG", sprintf("%s(%s)��%s����������200���ƽ𡣣�win��\n",
//		me->query("name"), getuid(me), ctime(time())));

	return 1;
	}

	else
	return 0;
}
