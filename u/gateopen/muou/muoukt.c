// By FunBoo@sz
// ľż��̨

#include <ansi.h>
inherit ROOM;
int do_practice(string arg);
int do_study(string arg);

// Function declearation
string look_gaoshi();	// for user look gaoshi

void create()
{
        set("short", HIG"��̨"NOR);
        set("long",
"�����ǿ�ľż��ĵĿ�̨������ǰ�������Ĵ�����һ���ų��ʣ���ǰ����
һ������ľż���̨�ӡ�̨����������ľż�ڱ���ľż�磬������̨������ˮй
��ͨ������һ��߹�һ��ľż̨������һ�Ÿ�ʾ(gaoshi)\n"
        );

        set("valid_startroom", 1);

        set("no_fight", 1);
        set("no_practice", 1);

        set("exits", ([
                "west": "/clone/misc/naihe/dc_horse",
        ]));

		set("item_desc", ([
		"gaoshi": (: look_gaoshi :),
		]));

        set("objects", ([
                "d/city/npc/yiren":1,
        ]));

        setup();
        call_other( "/clone/board/muoub", "???" );
}

void init()
{
                  add_action("do_practice",  "practice");
                  add_action("do_practice",  "lian");
                  add_action("do_study",  "study");
                  add_action("do_study",  "du");
}

int valid_leave(object me, string dir)
{
    if( dir=="west" )
	{
		if( wizardp(me) || (!me->query_temp("n_Muou_Cannot_Leave")))
		{
			return 1;
		}
        else
        {
			// Do not allow player leave
			if( me->query_temp("n_Muou_Cannot_Leave") )
			{
				return notify_fail("���Ǯ�ˣ����ڲ����뿪��\n");
			}
        }
	}
    return ::valid_leave(me, dir);
}

int do_practice(string arg)
{
	object me = this_player();
    tell_object(me, "���ﲻ׼����!\n");
    return 1;
}

int do_study(string arg)
{
	object me = this_player();
	tell_object(me, "���ﲻ׼����!\n");
	return 1;
}

string look_gaoshi()
{
	string msg;
	msg = "ľżϷʹ�ù���\n";
	msg+= "���ȸ�һ���ƽ������(give 1 gold to yiren)��Ȼ��Ϳ������ľż�ˡ�\n";
	msg+= "������������ľżϷ���������������ľż�����˲�������������Ǯ��\n";
	msg+= "\n";
	msg+= "�����������Ǯ֮������setmuou�����������ľż������Ҫ��Ƶ���Ŀ���£�\n";
	msg+= "��һ�����Ŀ��\n";
	msg+= "���䣺		setmuou age ��Ŀ (20 �� 200)\n";
	msg+= "���ܵȼ���	setmuou skill ��Ŀ (1 �� 800)\n";
	msg+= "�ķ��ȼ���	setmuou xinfa ��Ŀ (1 �� 800)\n";
	msg+= "������		setmuou str ��Ŀ (12 �� 30)\n";
	msg+= "������		setmuou int ��Ŀ (12 �� 30)\n";
	msg+= "���ǣ�		setmuou con ��Ŀ (12 �� 30)\n";
	msg+= "����		setmuou dex ��Ŀ (12 �� 30)\n";
	msg+= "���ɣ�		setmuou menpai menpai (���磺shaolin, wudang, quanzhen...)\n";
	msg+= "\n";
	msg+= "ȫ���츳���ܺͲ��ܳ�����ʮ���������Ǿ�ʮ��\n";
	msg+= "������������������˾ͻ��������Ȼ���ڽ���Ƶ����������Ҷ��ֻ�ʼľżϷ��\n";
	msg+= "�����ϵ��κ�һ������û�����㣬ľżϷ�����Ὺʼ��\n";
	msg+= "Ҳ����˵��������ĳ����Ŀ��ƴ��ˣ�������ͬ���������������һ�Ρ�\n";
	msg+= "���ǣ�������������˾Ͳ�������������ˡ�\n";
	msg+= "\n";
	msg+= "�����ǿ�����ƻ���Ƶ���Ŀ��\n";
	msg+= "�ڶ������Ŀ��\n";
	msg+= "��а����        setmuou pxj 1 Ϊľż����ʹ�ñ�а����\n";
	msg+= "����������	setmuou deathcount ��Ŀ Ϊľż����������������\n";
	msg+= "��������������ƵĻ���ľż��Ĭ�����Ϊ����ʹ�ñ�а������������һ�ٴΡ�\n";
	msg+= "�ڶ������Ŀ����Ҫ�ڵ�һ�����Ŀ���ǰ�趨��\n";
	msg+= "\n";
	msg+= "����㲻�������ô��ĵ�һ��Ŀ��������Ĭ�ϵ�һ��Ŀ��\n";
	msg+= "���setmuou default 1\n";
	msg+= "�����������ϵͳ�ͻ����ľżΪ��\n";
	msg+= "���䣺��ʮ�����ܺ��ķ��ȼ����İ١�����������������ʮ��������ʮ����������һ�١�\n";
	msg+= "����㲻���������κ�һ���������setmuou menpaiǰ������ơ�\n";
	msg+= "\n";
	msg+= "����ѡ��ı�����jian, dao, zhang, zhen, bang, bian�ȵ�...\n";
	return msg;
}