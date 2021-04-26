// xueshan/luyeyuan.c ¹ҰԷ

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        object ob;

        set("short", "¹ҰԷ");
        set("long", @LONG
һ����������������Ī���·���ӿ������С·��Ȼ���ʣ����
��ǰ����һ�鳤������ݺͲ�֦ʲ�������֣���ֻ¹��Ծ����С��߽�
���֣���Ҷ��ϥ�һ��˫������䣬����һ����(lianzuo)��������
ᦸǡ�������¹���ʯ��������ʢ���㻨����ľ��
LONG);

        set("exits", ([
                "east" : __DIR__"wangyou",
        ]));
        set("item_desc", ([
                "lianzuo" : "�������м�����̳����档\n",
        ]));

        set("cost", 2);
        set("outdoors","qilian-shan");
		set("objects", ([
        //        "/d/qilian/obj/lx-jing" : 1,
                "/d/xueshan/obj/lx-jing" : 1,
	]));
        setup();
        
}

void init()
{
        add_action("do_sit", "sit");
        add_action("do_stand", "stand");
        add_action("do_understand", "understand");
        add_action("do_understand", "lingwu");
        add_action("do_exercise",  "exercise");
        add_action("do_exercise",  "dazuo");
        add_action("do_respirate",  "respirate");
        add_action("do_respirate",  "tuna");
        add_action("do_practice",  "practice");
        add_action("do_practice",  "lian");
        add_action("do_practice",  "xiulian");
        add_action("do_study",  "study");
        add_action("do_study",  "du");
}

int do_sit(string arg)
{
        object me=this_player();

        object you = query("zuo");

        if( !arg || arg!="lianzuo" ) 
		return 0;

        if( me->query_temp("sitted"))
                return notify_fail("���Ѿ����������ˣ�\n");

        if(query("zuo") && strsrch(file_name(environment(you)), "/d/xueshan/luyeyuan") != -1) {
                write(query("zuo")->name()+"�Ѿ����������ˣ�\n");
                tell_object(query("zuo"), "������"+me->query("name")+"Ҳ����������\n");
                return 1;
        }

        if( arg == "lianzuo") {
        	message_vision("$N̤����������ס����涫������\n", me);
	        if(query("zuo")) {
                	you->delete_temp("sitted");
                	you->delete_temp("apply/short");
        	}
        	if ( me->query_skill("lamaism", 1) < 150) {
                	me->unconcious();
                	return 1;
        	}
                message_vision(HIY"��ľ������ȼ��$N�����������������֪���Ȼ�԰�������������������͡�\n"NOR, me);
                me->set_temp("sitted", 1);
                me->set_temp("apply/short", ({ me->query("title")+ " " +me->query("name")+"("+capitalize(me->query("id"))+")"+HIY" <����������>"NOR}));
                set("zuo", me);
                return 1;
        }
        return 1;
}

int do_stand()
{
        if (this_player()->query_busy())
                return notify_fail("�㻹����վ������\n");

        if (!this_player()->query_temp("sitted"))
                return notify_fail("��û�����������ϣ�\n");

        message_vision("$Nվ������������������\n", this_player());
        this_player()->delete_temp("sitted");
        this_player()->delete_temp("apply/short");
        set("zuo", 0);
        return 1;
}

int valid_leave(object me, string dir)
{
        if (me->query_temp("sitted"))
        	return notify_fail("�����ߣ�\n");
        return ::valid_leave(me, dir);
}

int do_exercise(string arg)
{
        object me = this_player();

        if( me->query_temp("sitted")) {
        	tell_object(me, "�������������򹦷�û��Ͼ���������飡\n");
        	return 1;
        }
        return 0;
}

int do_respirate(string arg)
{
        object me = this_player();

        if( me->query_temp("sitted")) {
	        tell_object(me, "�������������򹦷�û��Ͼ���������飡\n");
        	return 1;
        }
        return 0;
}

int do_practice(string arg)
{
        object me = this_player();

        if( me->query_temp("sitted")) {
	        tell_object(me, "�������������򹦷�û��Ͼ���������飡\n");
        	return 1;
        }
        return 0;
}

int do_study(string arg)
{
        object me = this_player();

        if( me->query_temp("sitted")) {
	        tell_object(me, "�������������򹦷�û��Ͼ���������飡\n");
        	return 1;
        }
        return 0;
}

int do_understand(string arg)
{
        mapping skills, learned;
        object me;
        string skillname;
        int skill_special, skill_basic;

        me = this_player();
        skills = me->query_skills();
        learned = me->query_learned();

        if (!me->query_temp("sitted")) 
		return 0;
     
        if( !arg ) 
                return notify_fail("��Ҫ�о����ֻ����似��\n");

        if( arg == "force" )
                return notify_fail("�㲻���������������ڹ���\n");

        if( arg != "cuff" && arg != "strike" && arg != "hand" && arg != "staff" && arg != "sword" && arg != "hammer" && arg != "blade" && arg != "dodge" && arg != "parry")
                return notify_fail("��ֻ�������������ŵ��书�ĵá�\n");

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

        me->receive_damage("jing", random(skill_basic), "��¹ҰԷڤ˼������Դ��������ˣ��װ׵��Խ�����һ��");

        if( me->query("potential") < 0) 
		me->set("potential", 0);

        skill_special = skill_special * me->query("max_jing") * 2 / (1000 + me->query("max_jing"));

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

        if( learned[arg] < 0 ) { 
                skills[arg]--;
                learned[arg] += skills[arg] * skills[arg];
        }

        return 1;
}
