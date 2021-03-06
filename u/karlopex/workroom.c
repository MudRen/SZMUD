/*-------------------------------------------------------------
** 文件名: workroom.c
** Copyright (c) 2000-2001
** 创建人: Karlopex
** 日  期: 2001/08/03
** 修改人: Karlopex
** 日  期: 2001/08/26
** 描  述: 葉楓的工作室
**-----------------------------------------------------------*/

#include <room.h>
#include <ansi.h>
#include "/clone/misc/string.h"
inherit ROOM;

void reset();
int valid_leave();
string tizi = CYN"\n\n┏━━━━━━━━━┯━━━━━━━━━━┓\n┃　"HIC"殘月當空映湖間"NOR+CYN"　│　"HIC"人生，掌握在手中"NOR+CYN"　┃\n"+
	"┃　"BLU"秋深風吹人心寒"NOR+CYN"　│　"BLU"命运，錯過時心痛"NOR+CYN"　┃\n┃　"HIB"岸邊孤楓葉飄凌"NOR+CYN"　│　"HIB"爱情，失去永不回"NOR+CYN"　┃\n"+
	"┃　"WHT"楓紅一時終离散"NOR+CYN"　│　"WHT"生命，昙花般瞬間"NOR+CYN"　┃\n┗━━━━━━━━━┷━━━━━━━━━━┛\n"+
	HIR"我已經失去自己所有的，不想再失去更多\n如果真再有一次機會，我會抓住她不放手\n"+
	"希望再見到妳，和妳一起繼續以前的快樂\n\n\n"NOR;


void create()
{
	set("short",CYN "凌枫工作室" NOR);
	set("long", "这里是叶枫的家，墙角有一张木板床，旁边是一张写字台(desk)，上
面放了一张相片(photo)和一本厚书，上面写着《谈经论道》(board)，墙
上挂着一幅书字画(zi)，他天天都在这里工作、休息。\n"
	);
	set("no_fight", 1);	      
	set("valid_startroom",1);
	set("sleep_room", "1");
					      
	set("exits", ([
                  "out" : __DIR__"hmsz-dy", 
	]));
        set("item_desc", ([
              "photo" : "这张照片上是叶枫和他的朋友的合影摹n",
              "zi" : string_m(tizi, 70)+NOR,
	      "desk"  : "这是一张普通的写字台，上面整齐地放着书、笔和一台电脑。\n",	
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
				message("vision",name+"被送到到了门外。"+"\n"+NOR,environment(me), ({me}));
				me->move(__DIR__"hmsz-dy");
				return;
			}
                message_vision("$N来到了凌枫工作室。"+"\n"+NOR,me);
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
        
	msga = "本站有这个巫师吗？\n";
	msgb = "还没有建立自己的工作室。\n";
			
	if ( !arg || arg == "" ) return notify_fail(HIG"你要去哪里？\n"NOR);

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
			message_vision(HIG+"司徒锦云劝道：$N不要在这里杀人！\n"+NOR,me);
        	        return 1;
                }else
                {
			message_vision(HIR+"天上一道闪电向$N劈去！\n$N慌张地向外逃去···"+NOR,me);
			me->move("/u/karlopex/hmsz-dy");
	                return 1;
                }
        }
}
int do_type(string arg) 
    {                                
              object me=this_player();
              int x,y;
        if( sscanf(arg, "%d %d", x, y)!=2 ) return notify_fail(HIG"你写什么？\n"NOR); 
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
