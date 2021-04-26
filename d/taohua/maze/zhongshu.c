// Code of ShenZhou
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	object ob;

        set("short", "ʯ������");
        set("long", @LONG
�����һ���ʯ���������ڵأ��ı�(wall)�ϻ��Ŷ�ʮ������ͼ������
�����������������󡣵���һ��̫��ͼ(tu)����Χ�ֱ������������
������ԣ���Ȧ�������ݶ�������ʮ���ԡ�һ�������Ȼע�£�ӳ������
�����������ƺ�������ţ����ƺ������ӳ£�����֮�䣬������ĥ��
LONG
        );

        set("exits", ([
                "up" : "/d/taohua/neidong",
        ]));
//        set("objects", ([
//                "/d/taohua/obj/guwen" : 1,
//        ]));
        set("no_fight", 1);
        set("item_desc", ([
                "tu" : "̫��ͼ����(yin)������(yang)��������ҡ�\n",
		"wall" :
"�������ޣ���ľ�ԡ���������ص���ѡ����º��������á�β�𻢡���ˮ��\n"
"�׻����ޣ���ľ�ǡ�¦�𹷡�θ���������ռ���������������ˮԳ\n"
"��ȸ���ޣ���ľ�����������⯡�����������¹����ˮ�ߡ������\n"
"�������ޣ���ľⳡ�ţ����Ů����������Σ���ࡢ�һ�����ˮ�����᣾\n",
        ]));

	set("cost", 1);

        setup();
}

void init()
{
        add_action("do_sit", "sit");
	add_action("do_stand", "stand");
	add_action("do_leave", "leave");
	add_action("do_understand", "understand");
		  add_action("do_understand", "lingwu");
        add_action("do_thinking", "think");  
//        add_action("do_thinking", "mingxiang");
}

int do_thinking()
{
	object me = this_player();
	int qmdj = me->query_skill("qimen-dunjia",1);

		  if ( me->query_skill("qimen-dunjia", 1) < 170 &&
		  !present("he tu", me) && !present("luo shu", me) ) {
		tell_object(me,MAG"��ֻ����Ѫ��ӿ�����������������Ϯ����\n"NOR);
					 me->unconcious();
					 return 1;
		  }

	if( !me->query("taohua_maze") ) {
					 tell_object(me,MAG"��ֻ����Ѫ��ӿ�����������������Ϯ����\n"NOR);
					 me->unconcious();
					 return 1;
	}

	if( me->query("jing") < 100 )
					 return notify_fail("�����ھ��񲻼ѣ��޷���������˼����\n");

		  if( (int)me->query("potential") <= 1 )
					 return notify_fail("���Ǳ�ܲ��㣬�޷���������书��\n");

		  me->receive_damage("jing", random(qmdj));
		  if( me->query("potential") < 0) me->set("potential", 0);

		  if(random(20) == 0) {
		  me->add("potential", -2);
					 me->improve_skill("qimen-dunjia", qmdj/2 + random(qmdj*2));
					 write( "ֻ�����л�Ȼ���ʣ�������Ŷݼ׵������ֽ���һ�㣡\n" );
		  }
		  else if(random(10) == 0) {
					 me->add("potential", -1);
					 me->improve_skill("qimen-dunjia", qmdj/5 + random(qmdj*2));
					 write( "��ڤ˼���룬�����Ŷݼ׽�������һ����ᣡ\n" );
	}
        else if(random(2) == 0) {
                me->improve_skill("qimen-dunjia", qmdj/10 + random(qmdj/2));
                write( "������������Ǳ�Ŀ�˼���Ŷݼ��ϵ��ѽ�֮����\n" );
        }
	else {
                write( "������������Ǳ�Ŀ�˼���Ŷݼ��ϵ��ѽ�֮����\n" ); 
	}

	return 1;
}

int do_sit(string arg)
{
        mapping skl;
        object me=this_player();
        string *sname;
        int i,j;

        if( !arg || arg!="yin" ) return 0;

	if( me->query_temp("sitted"))
		return notify_fail("���Ѿ����������ˣ�\n");

        if( me->query_temp("standed"))
                return notify_fail("���Ѿ�վ�������ˣ�\n");

	if( query("yin")){
		write(query("yin")->name()+"�Ѿ����������ˣ�\n");
		tell_object(query("yin"),"������"+me->query("name")+"Ҳ����������\n");
		return 1;
	}
/*
        skl = me->query_skills();
        sname  = keys(skl);
*/
        if( arg == "yin"){
	message_vision("$N��ϥ������������ͼ��\n", me);

	if ( me->query_skill("qimen-dunjia", 1) < 150 &&
	!present("he tu", me) && !present("luo shu", me) ){
		tell_object(me,MAG"��ֻ����Ѫ��ӿ�����������������Ϯ����\n"NOR);
					 me->unconcious();
		return 1;
		  }
		message_vision(HIG"$N�۹۱ǣ��ǹ��ģ�������ֹ������ֹ�����֮�����������⡣\n"NOR, me);
		me->set_temp("sitted", 1);
			set("yin", me);
		return 1;
		  }
	return 1;
}

int do_stand(string arg)
{
		  mapping skl;
		  object me=this_player();
        string *sname;
        int i,j;

        if( !arg || arg!="yang" ) return 0;

        if( me->query_temp("standed"))
                return notify_fail("���Ѿ�վ�������ˣ�\n");

        if( me->query_temp("sitted"))
                return notify_fail("���Ѿ����������ˣ�\n");

        if( query("yang")){
                write(query("yang")->name()+"�Ѿ�վ�������ˣ�\n");
		tell_object(query("yang"),"������"+me->query("name")+"Ҳ��վ������\n");
                return 1;
        }
/*
        skl = me->query_skills();
        sname  = keys(skl);
*/
        if( arg == "yang"){
        message_vision("$N����վ�����������ͼ��\n", me);

        if ( me->query_skill("qimen-dunjia", 1) < 150 &&
        !present("he tu", me) && !present("luo shu", me) ){		
		tell_object(me,MAG"��ֻ����Ѫ��ӿ�����������������Ϯ����\n"NOR);                
		me->unconcious();
                return 1;
        }
		message_vision(HIY"$N�����鲽�Ⱥ�����Է�λ������������죬Ƭ�̼������ﲻ���ڻ���\n"NOR,me);
		me->set_temp("standed", 1);
		set("yang", me);
		return 1;
        }
        return 1;
}

int do_leave()
{
	object me;

	me = this_player();
	if (me->query_temp("sitted")) {
		me->delete_temp("sitted");
		delete("yin");
		message_vision("$N����һ��������������վ��������\n",me);
	}

        if (me->query_temp("standed")) {
                me->delete_temp("standed");
                delete("yang");
		message_vision("$N��ϢƬ�̣�ͣס����������ȥ�е�ƣ�롣\n",me);
		  }

	return 1;
}

int valid_leave(object me, string dir)
{
		  if (me->query_temp("sitted") || me->query_temp("standed"))
		  return notify_fail("���������δ�ϣ�����������ˣ�\n");
		  return ::valid_leave(me, dir);
}

int do_understand(string arg)
{
		  object me;
		  string skillname;
		  int skill_special, skill_basic;

		  me = this_player();

	if (!me->query_temp("sitted") && !me->query_temp("standed") )
		return 0;

	if( !query("yin") || !query("yang") )
		return notify_fail("�㻹��Ҫһλͬ��Э���˹���\n");

	if( !arg )
					 return notify_fail("��Ҫ�о����ֻ����似��");

		  if( arg == "force" )
					 return notify_fail("�㲻���������������ڹ���\n");

		  if (me->is_busy())
					 return notify_fail("��������æ���ء�\n");

		  if( me->is_fighting() )
					 return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

		  if( !stringp(skillname = me->query_skill_mapped(arg)) )
					 return notify_fail("������������书����������似��������\n");

	skill_basic = me->query_skill(arg, 1);
		  skill_special = me->query_skill(skillname, 1);

		  if( skill_special < 1 )
					 return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");
		  if( skill_basic > skill_special )
					 return notify_fail("��" + to_chinese(skillname) + "�����������޷���������" + to_chinese(arg) + "��\n");
		  if( skill_basic < 1 )
					 return notify_fail("�����û��ѧ������������ܰɣ� �����ȥ��̱��ˡ�\n");

		  if ( me->query("jing") < 100 )
					 return notify_fail("�����ھ��񲻼ѣ��޷���������˼����\n");

		  if( (int)me->query("potential") <= 1 )
					 return notify_fail("���Ǳ�ܲ��㣬�޷���������书��\n");

		  me->receive_damage("jing", random(skill_basic));
		  if( me->query("potential") < 0) me->set("potential", 0);

	if(random(20) == 0) {
		me->add("potential", -2);
		me->improve_skill(arg, skill_special + random(skill_special*2));
		write( "ֻ�����л�Ȼ���ʣ����" + to_chinese(arg) + "�������ֽ���һ�㣡\n" );
	}
	else if(random(10) == 0) {
		me->add("potential", -1);
		me->improve_skill(arg, skill_special/2 + random(skill_special/1));
		write( "��ڤ˼���룬��" + to_chinese(arg) + "��������һ����ᣡ\n" );
	}
	else if(random(5) == 0) {
		me->add("potential", 0);
		me->improve_skill(arg, skill_special/4 + random(skill_special/2));
		write( "�����ֱȻ��ţ��ƺ���" + to_chinese(arg) + "�еļ�������������ᡣ\n" );
	}
	else if(random(2) == 0) {
		me->improve_skill(arg, skill_special/8 + random(skill_special/4));
		write( "������������Ǳ�Ŀ�˼" + to_chinese(arg) + "�ϵ��ѽ�֮����\n" );
	}
	else if(random(5) == 0) {
		write( "������˵�����ķ����" + to_chinese(arg) + "ʼ�ղ���һ�⡣\n" );
	}
	else if(random(10) == 0) {
		me->improve_skill(arg, - (skill_special/10 + random(skill_special/5)));
		write( "��ֻ�������������Ҵܣ�" + to_chinese(arg) + "�е���ʽ�������һ������ǰ���֣�\n" );
	}
	else if(random(20) == 0) {
		me->improve_skill(arg, - (skill_special/6 + random(skill_special/3)));
		write( "��Ĵ�����һƬ�հס���" + to_chinese(arg) + "��Խ��Խ��Ϳ��\n" );
	}
	else {
		write( "������������Ǳ�Ŀ�˼" + to_chinese(arg) + "�ϵ��ѽ�֮����\n" );
	}

		  return 1;

}
