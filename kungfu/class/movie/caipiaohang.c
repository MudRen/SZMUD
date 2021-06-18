/* /kungfu/class/movie/cphang.c
** ���ݲ�Ʊ��
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
        set("short", "������");
        set("long", @LONG
���������ݵĲ����У�ר�ŷ���������ͨ�õĸ�����Ʊ��ÿ�ڿ�����
����ר�ŵĹ��档�м�����һ������ӣ�sign�������湫���˱��ڿ�����
���룬�͸��Ƚ��Ľ�Ʒ���������⡣
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
	{	write("ĿǰΪֹ��û������\n");
        return "";
	}

	write(HIW"���ڸ�����Ʊ�����������ǣ�"+(string)jdata[0]+"\n");
	write(HIW"���ڸ�����Ʊ���н�����ͽ�Ʒ�ֱ����£�\n\n");
	for (i=1; i<sizeof(jdata); i++)
		if (sscanf(jdata[i],"%s@%d@",jpin,num) == 2)
			write(HIG+chinese_number(i)+"�Ƚ����룺 "+ tostring(num)+"    ��Ʒ�� "+ jpin +"\n"NOR);

	if (!query_typejiang())
	{	write("ĿǰΪֹ��û��������콱��\n");
                return "";
	}

	write(HIW"\n\n���ڸ�����ƱĿǰΪֹ���콱������У�\n\n");
	for (i=0; i<sizeof(typejiang); i++)
		if (sscanf(typejiang[i],"%d@%s@%d",num,usr,mark) == 3)
		{	write(HIG+chinese_number(num)+"�Ƚ�����ߣ� "+ usr+NOR);
			if(mark == 1)
				write(HIG"  ����Ʒ�Ѿ��䷢��\n"NOR);
			else
				write(HIG"  ����Ʒ��δ�䷢��\n"NOR);
		}

	write(HIY"\nлл����֧�֣�ף�����ˣ�\n"NOR);
	write(HIY"                   ----- ������Ʊ�� \n"NOR);
        return "";
}


int do_kaijiang(string arg)
{
	int tnum,i;
	object me = this_player();


	i = 0;

	if (!wizardp(me))
		return notify_fail("ֻ����ʦ����Ȩ��������\n");

	jdata = allocate(20);
	tnum = query_num();
	if ( tnum < 20)
		return notify_fail("����������ӵ�в�Ʊ������̫�٣����ʺϿ�����\n");


        write("������������Ƚ��ľ��影Ʒ����.�Ž������룩\n");
	write("�����뱾�θ�����Ʊ���������⣺\n");
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
		{	write("����Ҫ��һ�Ƚ��ɡ�\n");
			input_to("input_fun",0,1);
			return;
		}

		CPSYS->save_jiangdata(jdata);
		write("��������������ϡ�\n");
		CPSYS->typenone();
		shout(HIG"����Ʊ�С������ڸ�����Ʊ�������ʼ���뵽�����в�ѯ�н�����ͽ�Ʒ��лл���룡\n"NOR);
		write(HIG"����Ʊ�С������ڸ�����Ʊ�������ʼ���뵽�����в�ѯ�н�����ͽ�Ʒ��лл���룡\n"NOR);
		return;
	}

	tnum = query_num();
	jnum = 1 + random(tnum);

	while (do_guolv(jnum))
		jnum = 1 + random(tnum);

	CPSYS->add_ban(tostring(jnum));

	write(chinese_number(i)+"�Ƚ��Ľ�ƷΪ��"+ arg + "\n");
        write("���������"+chinese_number(i+1)+"�Ƚ��Ľ�Ʒ��\n");
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
		return notify_fail("ֻ����ʦ����ʹ�����ָ�\n");

        if (!arg)
        	return notify_fail("��Ҫ��Ǽ��Ƚ��Ѱ䷢��\n");

        if (sscanf(arg,"%d",lev)!= 1)
                return notify_fail("��Ҫ��Ǽ��Ƚ��Ѱ䷢��\n");

	if (CPSYS->add_mark(tostring(lev)) == 0)
		return notify_fail(lev+"�Ƚ�Ŀǰ��û��������ȡ��\n");

	if ( objectp (boss = present("boss",where)))
        	CHANNEL_D->do_channel(boss, "chat", me->name() + "��"+ me->query("id")+"����"+chinese_number(lev)+"�Ƚ���Ʒ�Ѿ��䷢����л��ҵĲ��롣\n");


	write("�ɹ���ǳ��Ѱ䷢��\n");
	return 1;
}

int do_faxing(string arg)
{
	int total;
	int i ,num ,tnum;
	object cp;
	object me = this_player();

	if (!wizardp(me))
		return notify_fail("ֻ����ʦ����ʹ�����ָ�\n");

        if (!arg)
        	return notify_fail("��Ҫ���м��Ų�Ʊ��\n");

        if (sscanf(arg,"%d",total)!= 1 || total < 1)
                return notify_fail("��Ҫ���м��Ų�Ʊ��\n");

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
        write("������Ҫ�Ĳ�Ʊ�����պú����������������и���ң�\n");
        return 1;
}
