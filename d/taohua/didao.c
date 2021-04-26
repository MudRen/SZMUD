// Code of ShenZhou
//kane

#include <ansi.h>
#include <mudlib.h>
#include "localtime.h"

inherit ROOM;


string* dirs = ({
        "ǫ", "Ǭ", "��", "��", "��", "��", "��", "ʦ", "��", "С��", "��", 
	"̩", "��", "ͬ��", "����"
});


void create() {
	set("short", "�ص�");
	set("long", @LONG
����һ��ʯ��������ֱͨ���ҩʦ���˷�����������֮����������ÿ��
ԼĪ����������һյʢ�����͵�����ƾ���ȼ�ա����й���ʮ�ֻ谵������ǿ
Ҳ�ɼ������ͷ��һ��ʯ��(men)���ű�Ƕ��һ������(tieban)��
LONG
	);
	set("cost", 1);
        
	set("item_desc", ([
        "men" :
"\n���Ͽ�����ʮ�������ų����������һ������
��ս���ϸһ����ԭ�����澡�����ģ��У���������
���׾���������ȴ�ֲ���Ѱ���������У��Ե���Щ��
�֣�ÿһ��������΢͹���ƺ����԰�(press)��ȥ��

�Ա�ע��һ��С�֣���ض�λ��ɽ��ͨ�����׷��ౡ��
ˮ�����䡣
\n",
        "tieban" : 
"\n�Ź�֮ͼ��������꣬����Ϊ�磬����Ϊ�㣬
�������ߣ�������һ��������롣

��һ����������֮����ѭ����Ϣ���˲��ܲ⣬��
�Դ�Ϊ��������Ź�ͼ�У������գ���֪����
�г����Զ���������ߣ���Ϊ������
\n"
	]));


        set("exits", ([
                "out" : __DIR__"xiangzhong",
	]));	
	
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_push", "press");
	add_action("do_help", "sos"); 
}

int do_help(string arg)
{
	object me = this_player();
	int n;
	mixed *local;
	
	if (!wizardp(me)) {
		tell_object(me, HIB"�Ϲ��˸����㣺 ������!!!\n"NOR);
		me->move("/d/death/blkbot");
		return 1;
	}

	local = localtime(time());
	n = (int)query_temp("number");
        log_file("Taohua",sprintf("%s(%s) used SOS in didao.c on %s\n",
                me->name(), getuid(me), ctime(time())));

	tell_object(me, HIB"�Ϲ��˸����㣺 "+dirs[n]+"!!!\n"NOR);
	return 1;
}

int do_push(string arg)
{
	object me = this_player();
//	object room = load_object(__DIR__"grave");
	object ob;
	int m,n,i,j,k;
	string str;

	me->add_temp("push_time", 1);
	message_vision("$N������ʯ�Ű�ȥ...\n", me);
	if (me->query_temp("push_time") >= 3 ) {
		tell_object(me,HIR"�����һ�飬���а��С����ã�����ֻ��һ��������ת......\n"NOR);
		me->unconcious();
		me->delete_temp("push_time");
		me->move(__DIR__"xiangzhong");
		return 1;
	}

	m = random(105);
	n = m%15;
	i=m%3; j=m%5; k=m%7;
	str = "�����ﲻ֪������������֮ʣ"+chinese_number(i)+"��������֮ʣ"+chinese_number(j)+"��������֮ʣ"+chinese_number(k)+"�����Ｘ�Σ�\n";

//	if (!arg) return notify_fail("ʲ�᣿\n");
	 
	if (arg == "ǫ") {
		write("ʯ��ͻȻ�������������˼�����\n");
		write("\n��������ȻƮ��һ�������ᣬ\n");
		ob = new(__DIR__"obj/paper3");
		ob->set("long", str);
		set_temp("number", n);
		ob->move(me);
		set_temp("th_tomb_pass1",1);
		me->start_busy(2);
	}

	if ((arg == dirs[query_temp("number")]) && (query_temp("th_tomb_pass1"))) {
                write("ʯ��ͻȻ�������������˼�����\n");
                set_temp("th_tomb_pass2",1);
	} 

	if (query_temp("th_tomb_pass1") && query_temp("th_tomb_pass2")) {
		write("ֻ���á�¡¡���������죬ʯ�Ż�����һ�໮��...\n\n\n");
		set("exits/enter", __DIR__"grave");
		remove_call_out("close_door");
		call_out("close_door", 10, me);
	        log_file("Taohua",sprintf("%s(%s) entered Taohua Tomb on %s. \n",
                                me->name(), getuid(me), ctime(time())));
		me->start_busy(2);
	} else return notify_fail("�㰴������һ�����󣬵�ʯ��ȴ��˿������\n");

	return 1;
}

void close_door()
{
//        object room = load_object(__DIR__"secret_path1");

        if( !query_temp("th_tomb_pass1") || !query_temp("th_tomb_pass2")) 
		return;

        message("vision", "����һ�����ʯ������ع����ˣ�һ���ָֻ�����ǰ�����ӡ�\n", this_object() );
        delete("exits/enter");
//        room->delete("exits/up");
//        tell_room(room, "����һ�������������ع����ˡ�\n");
        delete_temp("th_tomb_pass1");
	delete_temp("number");
	delete_temp("th_tomb_pass2");
}
