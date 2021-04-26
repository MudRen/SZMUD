//                ��׼��������ʾ��                                   |
// ˽�������ң�����snoop�������ˡ�
// by naihe  2002-07-04

#include <ansi.h>
inherit ROOM;

string welcome,host1,host2,now,
welcome="no",
host1="naihe",
host2="spark",
now="close";

void create()
{
	set("short", HIW"˽��������"NOR);
	set("long", HIR"\n�����κε�˽�������ң���������������������ȫ������������ϵ��\n\n"NOR"������������ out �������������� heal hp ������ʳ������ heal food ��\n��������� welcome <id> ���߳��Ŀ��� kickout <id> ��\n���÷���״̬�� sethere <open/close>.\n\n");
	set("invalid_startroom",1);

	set("exits", ([
//	    "out": __DIR__"naihe_room",
	    ]));

	setup();
}

void init()
{
//	::init();

	object me=this_player();
	if(me->query("id")=="naihe" || me->query("id")=="spark")
	{
		add_action("do_welcome","welcome");
		add_action("do_kickout","kickout");
		add_action("do_sethere","sethere");
	}

	add_action("do_out","out");
	add_action("do_heal","heal");	

	add_action("do_grope","grope");
	add_action("no_allchat","chat");
	add_action("no_allchat","chat*");
	add_action("no_allchat","rumor");
	add_action("no_allchat","rumor*");
	add_action("no_allchat","wiz");
	add_action("no_allchat","wiz*");
	add_action("no_allchat","gwiz");
	add_action("no_allchat","gwiz*");
	add_action("no_allchat","sz");
	add_action("no_allchat","sz*");
	add_action("no_allchat","jiaoyi");
	add_action("no_allchat","jiaoyi*");
	add_action("no_allchat","menpai");
	add_action("no_allchat","menpai*");
	add_action("no_allchat","tell");
	add_action("no_allchat","paimai");
	add_action("no_allchat","paimai*");
	add_action("no_allchat","to");
	add_action("no_allchat","tune");

	add_action("no_wiz","shout");
	add_action("no_wiz","goto");
	add_action("no_wiz","summon");
	if(this_player()->query("id")!="naihe")
        {
		add_action("no_wiz","update");
	add_action("no_wiz","more");
	add_action("no_wiz","cat");
                add_action("no_allchat","reply");
        }
	add_action("no_wiz","home");
	add_action("no_wiz","snoop");
	add_action("no_wiz","call");
	add_action("no_wiz","smash");
	add_action("no_wiz","destroy");
	add_action("no_wiz","clone");
	add_action("no_wiz","info");
	add_action("no_wiz","localcmds");
	add_action("no_wiz","tail");
	add_action("no_wiz","data");
	add_action("no_wiz","dest");
	add_action("no_wiz","possess");

/* ��ʱ�������©�Ĳ��֡�
	add_action("no_wiz","
	add_action("no_wiz","
	add_action("no_wiz","
	add_action("no_wiz","
*/

	if(me->query("id")!=host1 && me->query("id")!=host2)
	{
		remove_call_out("greeting");
		call_out("greeting",0,this_object());
	}
	else
	{
		message("vision",HIW"��������("+me->query("id")+")\n"NOR,this_object());
		tell_object(me,"���������ͻȻ����һƬ�ž������������˿�����������ˡ�\n");
		me->delete("channels");
	}
}

void greeting()
{
	object me=this_player();

	if(now=="open" || me->query("id")==welcome)
	{
		message("vision",HIW"�п͵���("+me->query("id")+")\n"NOR,this_object());
		tell_object(me,"���������ͻȻ����һƬ�ž������������˿�����������ˡ�\n");
		me->delete("channels");
		return;
	}

	message_vision("$N���¶�����ײ�����ȴ��ϵͳ���˳�ȥ��\n",me);
	me->move(__DIR__"naihe_room");
	tell_object(me,"�㱻���˳�����\n");
	message("vision",(string)me->query("name")+"��˽���������ﱻ���˳�����\n",environment(me),me);
	return;
}

int no_wiz()
{
	write("��Ȼ��������ͱ�ʹ����ʦ�ֶ��˰ɣ�\n");
	return 1;
}

int no_allchat()
{
	write("���������޷���������κν�̸��\n");
	return 1;
}

int do_heal(string arg)
{
	object me=this_player();

	if(arg=="hp")
	{
		me->set("jing",(int)me->query("max_jing"));
		me->set("qi",(int)me->query("max_qi"));
		me->set("jingli",(int)me->query("max_jingli"));
		me->set("neili",(int)me->query("max_neili"));
		write("ok,hp�Ѿ��ָ���\n");
		return 1;
	}

	if(arg=="food")
	{
		me->set("food",500);
		me->set("water",500);
		write("ok,food�Ѿ��ָ���\n");
		return 1;
	}
	write("��Ҫ�ָ�ʲô�� heal <hp/food>\n");
	return 1;
}

int do_welcome(string arg)
{
	object who,me;
	me=this_player();

	if(!arg) return notify_fail("Ҫ����˭�ģ�\n");

	if(present(arg,environment(me)))
	{
		write(arg+"�Ѿ�����������\n");
		return 1;
	}

	who=find_player(arg);
	if(!who) return notify_fail("��Ҫ�����"+arg+"���ڲ������ء�\n");

	if((string)who->query_temp("last_channel_msg")=="okokok")
	{
		welcome=who->query("id");
		who->move(this_object());
		message("vision",HIW"��͵�����ӭ��ӭ��\n"NOR,this_object());
		return 1;
	}

	if((string)who->query_temp("last_channel_msg")=="nonono")
	{
		tell_object(me,"����Ҫ�����"+arg+"�ܾ��ˡ�\n");
		welcome="no";
		return 1;
	}

	tell_object(who,HIY"\n��ã�"+me->query("name")+"��Ҫ�����㵽˽�������������졣�����ͬ�⣬�븴�������ַ����벢�ȴ���\nrumor* okokok ����ô��һ�����������ʱ�򣬽�����ֱ���ƶ����ȥ��\n��������ڲ���ȥ���븴�������ַ����룺rumor* nonono ����Ϊһ����ò�Դ𸴡�\n������Ҳ�������κεķ�����(/u/naihe/naihe_room.c)ֱ�����룺 meeting ���������ҡ�\n\n"NOR);
	tell_object(me,"�Ѿ����������ˣ��Ժ�����ظ�һ�α�ָ��ѶԷ��ƶ�������\n");
	welcome=who->query("id");
	return 1;
}

int do_kickout(string arg)
{
	object who;

	if(!arg) return notify_fail("��Ҫ��˭ѽ������\n");
	who=present(arg,environment(this_player()));
	if(!who) return notify_fail("����û�������ѽ������\n");
	message("vision",this_player()->query("name")+"��"+who->query("name")+"��������\n",this_object());
	who->move(__DIR__"naihe_room");
	message_vision("$N��"+this_player()->query("name")+"������������˳�����\n",who);
	return 1;
}

int do_sethere(string arg)
{
	if(!arg || (arg!="open" && arg!="close"))
		return notify_fail("�� sethere <open/close> ָ�����趨Ϊ���λ򿪷�ģʽ��\n");
	now=arg;
	message("vision",HIW"���䱻"+this_player()->query("name")+"�趨Ϊ"+now+"����ʽ��\n"NOR,this_object());
	return 1;
}

int do_out()
{
	object me=this_player();
	me->delete_temp("last_channel_msg");
	message_vision("$N�뿪�������ҡ�\n",me);
	me->move(__DIR__"naihe_room");
	message_vision("$N�������������˳�����\n",me);
	if(me->query("id")==welcome) welcome="no";
	return 1;
}
