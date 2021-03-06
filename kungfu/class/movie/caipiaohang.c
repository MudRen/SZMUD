/* /kungfu/class/movie/cphang.c
** 扬州彩票行
** created by yujie
** created in 11/2001
*/

inherit ROOM;

#define CAIPIAO "/kungfu/class/movie/obj/caipiao"
#define CPNUM "/data/movie/caipiao/cpnum"
#define CPSYS "/adm/single/cpsys"
#define JIANGDATA "/data/movie/caipiao/jiangdata"
#define NUMBAN "/data/movie/caipiao/numban"
#define TYPEJIANG "/data/movie/caipiao/typejiang"

#include <ansi.h>
#include <inttostr.h>

nosave string *jdata;
nosave string *numban;
nosave string *typejiang;

string look_sign();
void input_fun(string,int);
void start_jiang();

void create()
{
        set("short", "博弈行");
        set("long", @LONG
这里是扬州的博弈行，专门发行神州里通用的福利彩票，每期开奖的
都有专门的公告。中间竖着一块大牌子（sign），上面公告了本期开奖的
号码，和各等奖的奖品。敬请留意。
LONG
        );

        set("item_desc", ([
                "sign" : (: look_sign :),

        ]));

        set("exits", ([
                "west" : "/d/city/xiangnanjie.c",
        ]));

        set("objects", ([
                __DIR__"npc/zhaodai" : 1,
                __DIR__"npc/boss"    : 1,

        ]));

        set("no_fight", 1);
        set("no_steal", 1);

        set("cost", 0);
        setup();
}

int query_num()
{	string arg;
	int num;

	arg = read_file(CPNUM);

	if (sscanf(arg,"%d",num) == 1)
		return num;

	return 0;
}

int query_jiangdata()
{
	string msg;
	if (file_size(JIANGDATA)<1)
		return 0;

	msg = read_file(JIANGDATA);
	jdata = explode(msg,"*");
	return 1;

}

int query_numban()
{
	string msg;

	if (file_size(NUMBAN)<1)
		return 0;

	msg = read_file(NUMBAN);
	numban = explode(msg,"*");
	return 1;

}

int query_typejiang()
{
	string msg;

	if (file_size(TYPEJIANG)<1)
		return 0;

	msg = read_file(TYPEJIANG);
	typejiang = explode(msg,"*");
	return 1;
}


void init()
{
	object me = this_player();

	if ( wizardp(me) )
	{	add_action("do_kaijiang","kaijiang");
		add_action("do_mark","mark");
		add_action("do_faxing","faxing");
	}
}

int do_guolv(int num)
{
	int ban,i;

	if (query_numban()== 0)
		return 0;

	for(i=0; i<sizeof(numban) ;i++)
		if (tostring(num) == numban[i])
			return 1;

	return 0;
}



string look_sign()
{
	int i;
	int num ,mark;
	string jpin,usr;


        if(!query_jiangdata())
	{	write("目前为止还没开过奖\n");
        return "";
	}

	write(HIW"本期福利彩票开奖的主题是："+(string)jdata[0]+"\n");
	write(HIW"本期福利彩票的中奖号码和奖品分别如下：\n\n");
	for (i=1; i<sizeof(jdata); i++)
		if (sscanf(jdata[i],"%s@%d@",jpin,num) == 2)
			write(HIG+chinese_number(i)+"等奖号码： "+ tostring(num)+"    奖品： "+ jpin +"\n"NOR);

	if (!query_typejiang())
	{	write("目前为止还没有玩家来领奖。\n");
                return "";
	}

	write(HIW"\n\n本期福利彩票目前为止来领奖的玩家有：\n\n");
	for (i=0; i<sizeof(typejiang); i++)
		if (sscanf(typejiang[i],"%d@%s@%d",num,usr,mark) == 3)
		{	write(HIG+chinese_number(num)+"等奖获得者： "+ usr+NOR);
			if(mark == 1)
				write(HIG"  （奖品已经颁发）\n"NOR);
			else
				write(HIG"  （奖品还未颁发）\n"NOR);
		}

	write(HIY"\n谢谢您的支持，祝您好运！\n"NOR);
	write(HIY"                   ----- 福利彩票行 \n"NOR);
        return "";
}


int do_kaijiang(string arg)
{
	int tnum,i;
	object me = this_player();


	i = 0;

	if (!wizardp(me))
		return notify_fail("只有巫师才有权利开奖。\n");

	jdata = allocate(20);
	tnum = query_num();
	if ( tnum < 20)
		return notify_fail("现在神州里拥有彩票的数量太少，不适合开奖。\n");


        write("请依次输入各等奖的具体奖品：（.号结束输入）\n");
	write("先输入本次福利彩票开奖的主题：\n");
        input_to("input_fun",0,0);
	return 1;
}


void input_fun(string arg,int i)
{
	int tnum , jnum;


	if (i == 0)
	{
		jdata[0]=arg;
		input_to("input_fun",0,1);
		return;
	}

	if (arg == ".")
	{	if (i ==1 )
		{	write("最少要有一等奖吧。\n");
			input_to("input_fun",0,1);
			return;
		}

		CPSYS->save_jiangdata(jdata);
		write("各个奖项设立完毕。\n");
		CPSYS->typenone();
		shout(HIG"【彩票行】：本期福利彩票开奖活动开始，请到博弈行查询中奖号码和奖品，谢谢参与！\n"NOR);
		write(HIG"【彩票行】：本期福利彩票开奖活动开始，请到博弈行查询中奖号码和奖品，谢谢参与！\n"NOR);
		return;
	}

	tnum = query_num();
	jnum = 1 + random(tnum);

	while (do_guolv(jnum))
		jnum = 1 + random(tnum);

	CPSYS->add_ban(tostring(jnum));

	write(chinese_number(i)+"等奖的奖品为："+ arg + "\n");
        write("请接着输入"+chinese_number(i+1)+"等奖的奖品。\n");
	jdata[i] = arg + "@" + tostring(jnum) +"@";

	i++;
	input_to("input_fun",0,i);
	return;
}


int do_mark(string arg)
{
	int lev;
	string name;
        object me = this_player();
        object boss;
	object where = this_object();

	if (!wizardp(me))
		return notify_fail("只有巫师才能使用这个指令。\n");

        if (!arg)
        	return notify_fail("你要标记几等奖已颁发？\n");

        if (sscanf(arg,"%d",lev)!= 1)
                return notify_fail("你要标记几等奖已颁发？\n");

	if (CPSYS->add_mark(tostring(lev)) == 0)
		return notify_fail(lev+"等奖目前还没有人来领取。\n");

	if ( objectp (boss = present("boss",where)))
        	CHANNEL_D->do_channel(boss, "chat", me->name() + "（"+ me->query("id")+"）的"+chinese_number(lev)+"等奖奖品已经颁发，感谢大家的参与。\n");


	write("成功标记成已颁发！\n");
	return 1;
}

int do_faxing(string arg)
{
	int total;
	int i ,num ,tnum;
	object cp;
	object me = this_player();

	if (!wizardp(me))
		return notify_fail("只有巫师才能使用这个指令。\n");

        if (!arg)
        	return notify_fail("你要发行几张彩票？\n");

        if (sscanf(arg,"%d",total)!= 1 || total < 1)
                return notify_fail("你要发行几张彩票？\n");

        tnum = query_num();
        num = tnum;

        for(i=0; i<total ;i++)
        {
        	cp=new(CAIPIAO);
        	num++;
        	cp->set("number",num);
        	cp->move(me);
        }
        CPSYS->set_num(tostring(num));
        write("这是你要的彩票，请收好后按照正常的渠道发行给玩家！\n");
        return 1;
}
