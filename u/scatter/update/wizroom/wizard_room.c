// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
// 神州贡献度 SET BY SCATTER

#include <ansi.h>
inherit ROOM;


void create()
{
                seteuid(getuid());


        set("short", HIY"黄金大殿"+NOR);
        set("long", @LONG
这里是一座黄金的殿堂，十分雄伟，黄琉璃瓦闪烁金光。前檐有七尺深，斗
拱、飞檐、彩绘承尘，四根一人抱不住的朱漆柱子。殿里正中间放着巨大的红木
圆桌，桌上凌乱地放着一叠叠的设计图纸与文稿，其中最引人注目的是一本缎子
面的小册子，上面书写着三个楷体「功勋册」(ce)。

最新功能 (BETA V 1.0)
checkgx <ID> (可以查看玩家的 神州 贡献度)
gxadd <ID> <AMOUNT> because <原因> (帮某个玩家加 神州 贡献度)
gxmin <ID> <AMOUNT> because <原因> (帮某个玩家减 神州 贡献度)

LONG
        );
        set("exits", ([ 
                  "up"  : "/d/wizard/meeting_room",
                  "west"  : "/d/death/noteroom",
                  "cl"  : "/d/forest/clzoulang2",                  
                  "down"  : "/d/wizard/guest_room",                  
                  
]));
        
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("cost", 0);
        setup();
        call_other("/clone/board/wiz_b", "???");
}

void init()
{
        object me = this_player();

                add_action("do_checkgx", "checkgx");
                add_action("do_gxadd", "gxadd");
                add_action("do_gxmin", "gxmin");

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}

int do_checkgx(string arg)
{
        object ob;
        int chkvalue;
        string outmsg;
        
        ob = find_player(arg);
        if(!ob->query("shenzhou/pts"))
        {
                write("这个玩家没有　神州 贡献度．\n");
                return 1;
        }

        chkvalue = ob->query("shenzhou/pts");
        outmsg = ob->name(1) + " 的 神州 贡献度为 " + chkvalue + " 点．\n";
        write(outmsg);
        return 1;
}

int do_gxadd(string arg)
{
        object ob;
        int addvalue;
        string strID;
        string msgvalue;
        string outmsg;
                string strRes;


        if( !arg || sscanf(arg, "%s %s because %s", strID, msgvalue, strRes)!=3 )
        {
                write("格式错误\n");
                return 1;
        }

        addvalue = atoi(msgvalue);
        
        ob = find_player(strID);

        ob->add("shenzhou/pts", addvalue);
                
                log_file("/awards/gxadd",this_player()->query("name") + " 给予"+ ob->query("name") + " (" + ob->query("id") + ") " + addvalue + "点, 因为" + strRes + " 在 " +ctime(time())+"\n"); 
        
                write("增加完毕\n");

        return 1;
}


int do_gxmin(string arg)
{
        object ob;
        int addvalue;
        string strID;
        string msgvalue;
        string outmsg;
                string strRes;


        if( !arg || sscanf(arg, "%s %s because %s", strID, msgvalue, strRes)!=3 )
        {
                write("格式错误\n");
                return 1;
        }

        addvalue = atoi(msgvalue);
        
        ob = find_player(strID);

        ob->add("shenzhou/pts", -addvalue);

                log_file("/awards/gxmin",this_player()->query("name") + " 减掉"+ ob->query("name") + " (" + ob->query("id") + ") " + addvalue + "点, 因为" + strRes + " 在 " +ctime(time())+"\n"); 

        write("减去完毕\n");

        return 1;
}

