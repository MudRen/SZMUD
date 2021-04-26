//                ��׼��������ʾ��                                   |
// �ĳ�VIP������������ǶĽ��ӵģ�heihei  ��dc_vip.c
// naihe  2002-04-29 ��ï��
// 2002-05-01��ɣ� by naihe
// �������Ը��ı��ļ�Դ�룬лл��

#include <ansi.h>
#include <room.h>
inherit ROOM;


void create()
{
	set("short", HIW"�����"NOR);
	set("long", "����һ�䲻��ķ��䣬������ȴ�������ɡ�ǽ�������ŵ��Ǵ���������ı�
ֽ������Ư���������ε���·���컨���ϵ���һ��������ȴ��ҫ�۵�ҹ���飬
����������������֮�������ա����µķ�������λ�ðڷ���һ��С�ɵĴ���ʯ
Բ�����������������ӣ�һ���𷢵����������ڶ��ŵ�������΢΢�ض���Ц�š�
�űߵ�ǽ������һ���������ɵ�Сˮ�أ����滹������βɷ�ǿɰ��Ľ��㣻�ر�
����һ�����ľ��С����(paizi) �������Ϸ�������һ��ͦ���ֽ������д�ż�
���֣����ľֹ���(guize)��

������ӵĴ����Ǳ����˹�������ʱ�е�һ���������������ġ�
\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("invalid_startroom",1);

	set("item_desc",([
	    "paizi":""YEL"
#############
# "HIY"find here"NOR""YEL" #
#############
"NOR"\n",
	    "guize":""HIG"
��������������������������������������������������������������������������������
��                              "HIR"��� �� �� ���"HIG"                               ��
��"HIR"�����ӡ�"HIG"                                                                    ��
��      ��ʽ��touzi <��Ŀ> <Ǯ��>  ����touzi 1 gold. ��˼����1���ƽ�Ϊ�׽�  ��
��      ���ӣ�ÿ�������ӳ�3�����ӣ���ӵ������߼�ʤ������Ϊ1��1��             ��
��      �����������3��������ͬʱ����������Ϊ5������ʱ���۵������٣���Ϊʤ��  ��
��                ����ׯ���ж���ͬ������˭�ĵ�����������Ϊ5����           ��
��                                                                            ��
��"HIR"����ţ��"HIG"                                                                    ��
��      ��ʽ��douniu <��Ŀ> <Ǯ��>    ����douniu 1 gold.                      ��
��      ��ţ����ÿ�������ƣ�1-13����10-13��Ϊ10���޻�ɫ��һ�ι���������㡣   ��
��      ���Ž�Ϊ10���ơ���ţ�����������Ϊ5����ͬ���������Ҫ����5����Ǯ������
��      �����������Ϊ10��20��30��Ϊ����ţ��������ţ����ʤ����ţ���ߡ�        ��
��      ����ţ��֮��ʣ���������Ϊ�����������߽���ţ���������ȴ�С��        ��
��      ����������ʮ������ͷ�㣻������10����̳ơ�ţţ��������Ϊ3����       ��
��      ����Ϊ8��9ʱ������Ϊ2��������Ľ�Ϊ1������˫��ͬ������ׯ��Ϊ��      ��
��                                                                            ��
��"HIR"��һ�Ŷ���Ӯ��"HIG"                                                              ��
��      ��ʽ��yizhang <��Ŀ> <Ǯ��>    ����yizhang 1 gold.                    ��
��      һ�Ŷ���Ӯ��ׯ���и���һ���ƣ�1-13����1��������13��12������2��С����
��      ��������ͬ����Ȼ�ɫ������С�����Դ󣬡���֮���������Ϸ����Ϊ1��1����
��                                                                            ��
��      ----������Ϸ����Ҫ���ٴ����ܹ�֧��������ʵĻƽ�������ܿ�ʼ�����綷ţ��
��          ��Ϸ��Ѻע1 goldʱ����������Ҫ���ٴ���5 gold��                    ��
��                                                     --by naihe 2002-05-06  ��
��������������������������������������������������������������������������������
"NOR"",
	]));

	set("objects", ([
	    __DIR__"npc/dc_boss" : 1,
	    ]));

	set("exits", ([
	    "out": __DIR__"dc_dating",
	    ]));

	create_door("out", "С��", "vip", DOOR_CLOSED);

	setup();
}

void init()
{
	add_action("do_skills",  "exercise");
	add_action("do_skills",  "dazuo");
	add_action("do_skills",  "respirate");
	add_action("do_skills",  "tuna");
	add_action("do_skills",  "practice");
	add_action("do_skills",  "lian");
	add_action("do_skills",  "study");
	add_action("do_skills",  "du");
	add_action("do_food", "eat");
	add_action("do_food", "chi");
	add_action("do_food", "drink");
	add_action("do_drop", "throw");
	add_action("do_drop", "drop");
	add_action("do_find","find");
        add_action("do_food", "he");
}

  void reset()
  {  
                ::reset();  
                set("no_clean_up",1);
  }
int do_skills(string arg)
{
	tell_object(this_player(),"Ҫ��Ǯ��ר�Ķģ�����������ˡ�\n");
	return 1;
}

int do_food(string arg)
{
	tell_object(this_player(),"�Զ����뵽��¥������\n");
	return 1;
}

int do_drop(string arg)
{
	if(arg=="gold") return 0;
	tell_object(this_player(),"�������Ӷ�����\n");
	return 1;
}

int do_find(string arg)
{
	object me,ob;
	int find;
	me = this_player();
	
	if(!arg)
	{
		if(me->query("jingli") < me->query("max_jingli")/2)
		return notify_fail("������ǰ���㼯�в�������Ѱ�ҡ�\n");

		me->set("jingli",30);
		find=random(200);
		if(find<10 || find>190) ob=new("/clone/money/coin");
		if(find>9 && find <15) ob=new("/clone/money/silver");
		if(find>14 && find<30) ob=new("/clone/food/kaoya");
		if(find>29 && find<35) ob=new("/clone/money/gold");
		if(find>34 && find<40) ob=new("/clone/weapon/changjian");
		if(find==44 || find==88) ob=new("/clone/weapon/qinggang-jian");
		if(find==144 || find==188) ob=new("/clone/armor/tiejia");
		if(find>100 && find<110) ob=new("/clone/food/mitao");

		if(!ob)
		{
			message_vision("$N���˰��죬ʲôҲû�ҵ����۵�ͷ���ۻ���\n",me);
			return 1;
		}

		else
		{
		ob->set_amount(1);
		message_vision("$N�������˰��죬��ǽ�Ƿ�����һ" + ob->query("unit") + ob->query("name") + "��\n",me);
		ob->move(me);
		return 1;
		}
	}

	return 0;
}
