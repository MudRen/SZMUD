/*-------------------------------------------------------------
** �ļ���: workroom.c
** Copyright (c) 2000-2001
** ������: Karlopex
** ��  ��: 2001/08/03
** �޸���: Karlopex
** ��  ��: 2001/08/26
** ��  ��: �~���Ĺ�����
**-----------------------------------------------------------*/

#include <room.h>
#include <ansi.h>
#include "/clone/misc/string.h"
inherit ROOM;

void reset();
int valid_leave();
string tizi = CYN"\n\n���������������������ө���������������������\n����"HIC"���®���ӳ���g"NOR+CYN"������"HIC"����������������"NOR+CYN"����\n"+
	"����"BLU"�����L�����ĺ�"NOR+CYN"������"BLU"���ˣ��e�^�r��ʹ"NOR+CYN"����\n����"HIB"��߅���~�h��"NOR+CYN"������"HIB"���飬ʧȥ������"NOR+CYN"����\n"+
	"����"WHT"���tһ�r�K��ɢ"NOR+CYN"������"WHT"������꼻���˲�g"NOR+CYN"����\n���������������������۩���������������������\n"+
	HIR"���ѽ�ʧȥ�Լ����еģ�������ʧȥ����\n���������һ�ΙC�����ҕ�ץס��������\n"+
	"ϣ����Ҋ�������͊�һ���^�m��ǰ�Ŀ옷\n\n\n"NOR;


void create()
{
	set("short",CYN "��㹤����" NOR);
	set("long", "������Ҷ��ļң�ǽ����һ��ľ�崲���Ա���һ��д��̨(desk)����
�����һ����Ƭ(photo)��һ�����飬����д�š�̸���۵���(board)��ǽ
�Ϲ���һ�����ֻ�(zi)�������춼�����﹤������Ϣ��\n"
	);
	set("no_fight", 1);	      
	set("valid_startroom",1);
	set("sleep_room", "1");
					      
	set("exits", ([
                  "out" : __DIR__"hmsz-dy", 
	]));
        set("item_desc", ([
              "photo" : "������Ƭ����Ҷ����������ѵĺ�Ӱġ�\n",
              "zi" : string_m(tizi, 70)+NOR,
	      "desk"  : "����һ����ͨ��д��̨����������ط����顢�ʺ�һ̨���ԡ�\n",	
		]));

	set("objects", ([
		__DIR__"npc/jinyun" : 1,
//                __DIR__"obj/auto_seller" : 1,
        ]));
	set("no_clean_up", 0);
	set("wuhen_count", 1);
	set("cost", 0);

	setup();
        call_other("/clone/board/karlopex_b", "???");
}

void init()
{
        object me = this_player();
        string name = ( me->query("colorname") )?( me->query("colorname") ):(me->name());
        
        if ( interactive(me) && getuid(me) != "karlopex" )
        {
                if( !wizardp(me) && me->query("caninit") != "karlopex's workroom")
			{
				message("vision",name+"���͵��������⡣"+"\n"+NOR,environment(me), ({me}));
				me->move(__DIR__"hmsz-dy");
				return;
			}
                message_vision("$N��������㹤���ҡ�"+"\n"+NOR,me);
	}
        add_action("go_kaifeng", "kf");
        add_action("do_qu", "qu");
        add_action("do_smash", "smash");
        add_action("do_type", "type"); 
}

int do_qu(string arg)
{
        object me = this_player();
        string home = "/u/" + arg + "/workroom.c";
        string msga, msgb;
        
	msga = "��վ�������ʦ��\n";
	msgb = "��û�н����Լ��Ĺ����ҡ�\n";
			
	if ( !arg || arg == "" ) return notify_fail(HIG"��Ҫȥ���\n"NOR);

	if ( !wizardp(arg) )return notify_fail(HIY+msga+NOR);
	
	if( file_size(user_path(arg) + "workroom.c") <= 0 )
		return notify_fail(HIR+arg+msgb+NOR);

        me->move(home);
        return 1;
}
int do_smash(string arg)
{
        object me = this_player();

        if ( getuid(me) !="karlopex" && arg)
        {
		if (present("situ jinyun", environment(me)))
			{
			message_vision(HIG+"˾ͽ����Ȱ����$N��Ҫ������ɱ�ˣ�\n"+NOR,me);
        	        return 1;
                }else
                {
			message_vision(HIR+"����һ��������$N��ȥ��\n$N���ŵ�������ȥ������"+NOR,me);
			me->move("/u/karlopex/hmsz-dy");
	                return 1;
                }
        }
}
int do_type(string arg) 
    {                                
              object me=this_player();
              int x,y;
        if( sscanf(arg, "%d %d", x, y)!=2 ) return notify_fail(HIG"��дʲô��\n"NOR); 
              tell_object(me,x/y*3600+"\n"); 
              return 1; 
      } 
int go_kaifeng()
{
        if (wizhood(this_player()) != "(arch)" && wizhood(this_player()) != "(admin)" && getuid(this_player()) != "karlopex")
                return 1; 
        this_player()->move("/d/kaifeng/kaifengfu");
        return 1;
}
