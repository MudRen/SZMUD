//                ��׼��������ʾ��                                   |
// �ĳ�����  ��dc_door.c
// by naihe  2002-04-16

#include <ansi.h>
//#include <room.h>
inherit ROOM;

string temphere="open";
int t_enter;

void create()
{
set("short",HIY"�����á��ĳ�����"NOR);
	set("long","��վ�ڶĳ�����ǰ�棬��������ǽ���������ȫ�ǵ��¶ĳ��ˡ���˵�����
����һ�������˿��ģ�ȴ�������ԭ���Ķĳ��������мҶ��ƾš�ɫ��֮�࣬��
�������������Ļ�����ʹ����Щ���������жĲ������δ���Ź�������ʵĶ�
��������ǿ�ҵ����ȥ���������������ɵ����������Ϸ���һ��������ƣ�pai����
�ű��ϻ�����һ��"HIW"���볡��֪��"NOR"��xuzhi����\n");
	set("valid_startroom", 1);

	set("item_desc",([
	    "pai":""HIY"
������������
�������ĳ���
������������
"NOR"\n",
/*	    "xuzhi":"���뱾�ĳ���������Ʊһ�ţ�ÿ��1 GOLD��������ʱ���ԶԽ�����߽�50 GOLD����
������Ʊ�������ڡ���ֱ������ enter ������Ʊ�����롣��\n",
*/
	    "xuzhi":"�ĳ���Ϸ����ǿ���ƽ飺����ս����Ϸ������\n",
	]));

	set("objects", ([
	    __DIR__"npc/npcmoney" : 1,
	    ]));

	set("exits",([
	    "east":"/d/city/nandajie1",
	    "enter":__DIR__"dc_dating",
	    "south":"/d/city/duchang",
	]));


	setup();
}

void init()
{
	if(wizardp(this_player()))  add_action("do_mewiz", "mewiz");
// wiz ���Կ��Ż�ر���ڣ����� <mewiz open> �����Ŷĳ������� <mewiz close> ���رնĳ���
	if(wizardp(this_player()))  add_action("do_xxx","xxx");
	add_action("do_enter",  "enter");
}

  void reset() 
  { 
                ::reset(); 
                set("no_clean_up", 1); 
  } 

int do_mewiz(string arg)
{
	if(!arg) return notify_fail("��ʽ��<mewiz open> ���Ŷĳ���<mewiz close> �رնĳ���\n");
	if(arg=="open" || arg=="close")
	{
		if(arg=="close")
		{
		    if(temphere=="close") return notify_fail("���ڶĳ��Ѿ���ֹͣӪҵ���ˡ�\n");
		    message_vision(""HIW"$N�������˼�������ͼ������漴ð�����Ʊ��������Ѷĳ���������������"NOR"\n",this_player());
		}
		if(arg=="open")
		{
		    if(temphere=="open") return notify_fail("���ڶĳ��Ѿ�������Ӫҵ���ˡ�\n");
		    message_vision(""HIW"$N�������˼������Ũ��ɢ�����ĳ��������³��ֳ����ˡ�"NOR"\n",this_player());
		}
	temphere=arg;
	return 1;
	}

	write("��ʽ��<mewiz open> ���Ŷĳ���<mewiz close> �رնĳ���\n");
	return 1;
}

int do_xxx()
{
	write(HIW"���ڶĳ�״̬Ϊ��"+temphere+"����ʦ����ʹ�� <mewiz> ָ��Ż�رնĳ���\n�ܽ���������"+t_enter+" �ˡ�\n"NOR);
	return 1;
}

/*
int do_enter()
{
	object me,qian;
	me = this_player();
	qian = present("gold_money", me);

	if(temphere=="close")
	{
		write("�ĳ���ʱֹͣӪҵ�������������\n");
		return 1;
	}

	if(me->query("jingli") < 40)
	{
		write("���۵ÿ��߲����ˣ�����ЪЪ�ٽ�ȥ�ɣ�\n");
		return 1;
	}

	if(!qian)
	{
		write("������Ʊ�����𣬽�ȥĪ������͵��ƭ��������\n");
		return 1;
	}

	qian->add_amount(-1);
	tell_room(environment(me),(string)me->query("name")+"����һ����Ʊ�����˽�ȥ��\n",me);
	me->move(__DIR__"dc_dating");
	tell_object(me,""HIM"��������Ʊ�����˽�����"NOR"\n");
	tell_room(environment(me),(string)me->query("name")+"�Ӵ��ſ����˽�����\n",me);
	me->add("jingli", -30);

	return 1;
}
*/

int do_enter()
{
	if(temphere!="open")
	{
		write(HIW"�ĳ���ʱֹͣӪҵ�������������\n"NOR);
		return 1;
	}

	t_enter++;
	return 0;
}

