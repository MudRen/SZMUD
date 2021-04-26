// Code of ShenZhou
// /clone/misc/jinnang.c
// Wzfeng 4/1/1998
//������˵��:����,�ɴ����ҵ��ź������ж�����ӣ������ż��Ĺ��ܡ�

#include <ansi.h>

inherit ITEM;

inherit F_SAVE;
mapping *letters;
mapping letter;



int set_owner(string id)
{
        set("owner_id", id);
        return restore();
}
//���ô��̵��ļ�·�������ơ�
string query_save_file()
{
        string id;

        if( !stringp(id = query("owner_id")) ) return 0;

        return DATA_DIR + "letter/" + id[0..0] + "/" + id+"_jin";
}

//����ż��ĺ���
void add_letter(mapping letter)
{
        if( !pointerp(letters) )
        {
         letters = ({ letter });
        }
        else letters += ({ letter });

}

//ɾ���ż��ĺ�����
void cut_letter(mapping letter)
{
        if( !pointerp(letters) )
        {
         letters = ({ letter });
        }
        else letters -= ({ letter });

}



void create()
{
	set_name(CYN "����" NOR, ({ "jin nang", "nang" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "silk");
		set("no_get",1);
		set("no_drop","������������Ʒ���㲻����㶪����");
		set("no_insert", 1);
	}
	setup();
	
}

int query_autoload()
{
	return 1;
}
//��ʼ����Ʒ���趨���ҵ�������
void init()
{
	int letter_num,i;
	object ob,me;
	string letter_msg="";
	ob=this_object();
    me=this_player();
	set("master_id",this_player()->query("id"));
    set_owner(ob->query("master_id"));
	letter_num=sizeof(letters);

	for(i=0;i<letter_num;i++)
	{
		letter_msg+="��"+chinese_number(i+1)+"���ź�\t";
		letter_msg+="�����ű��⡿��"+letters[i]["title"]+"\t";
		letter_msg+=letters[i]["from"]+"д��"+letters[i]["time"]+"\n";
	}
if(letter_num)
{	
	set("long", "
����һ����������װ�ŵĽ��ҡ�\n"
"�����(read)�����ţ���(add)���������,��(discard)������ĳһ���š�\n"
"Ŀǰ����װ��"+chinese_number(letter_num)+"���ź���\n"
""+letter_msg+"\n"
);
}else
{
		set("long", "
����һ����������װ�ŵĽ��ҡ�\n"
"�����(read)�����ţ���(add)���������,��(discard)������ĳһ���š�\n"
"Ŀǰ����û��װ�κ��ź���\n");
}

    add_action("do_add", "add");
	add_action("do_read", "read");
	add_action("do_cut", "discard");

}

//�����ż��ĺ���
int do_cut(string arg)
{
        object ob;
        int i,num;

        ob=this_object();
		
    	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("��Ҫ������һ���ţ�\n");

        if( !pointerp(letters) || num < 1 || num > sizeof(letters) )
		return notify_fail("û�������ŵ��ż���\n");
		num --;
		write("��ӽ������ó�һ���ź�,����һ�ߡ�\n");
        cut_letter(letters[num]);
		save();
		init();
		
        return 1;
}


//����ż��ĺ���
int do_add(string arg)
{
    object ob,ob_letter;
    int i;
    mapping letter;
    
	if(!arg) return notify_fail("��Ҫ��ʲô�Ž������\n");
	ob_letter = present(arg, this_player());
	if(!ob_letter)
        return notify_fail("�����Ϻ���û������Ʒ��\n");
	if(!ob_letter->query("can_add_jinnang"))
        return notify_fail("�Բ������޷��������Ʒ�Ž������\n");
    if(!ob_letter->query("be_read"))
		return notify_fail("�㻹û�ж���������أ����ȶ�һ���ٷŽ����Ҳ��١�\n");

	if(sizeof(letters)>9)
	{
		return notify_fail("�����ѱ�װ����û�еط���������ˡ�\n");
	}

	letter=ob_letter->query("letter");
	add_letter(letter);
	save();
	init();
	destruct(ob_letter);
	write("�㽫һ���ź��Ž������С�\n");
	return 1;
}

//���ż��ĺ�����
int do_read(string arg)
{
        object ob;
        int i,num;

        ob=this_object();
		
    	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("��Ҫ����һ���ţ�\n");

        if( !pointerp(letters) || num < 1 || num > sizeof(letters) )
		return notify_fail("û�������ŵ��ż���\n");
		num --;

        printf("�����ű��⡿��%s\n�������ˡ���%s\n���ż����ݡ���\n%s\n\t\t%sд��%s\n\n\n",
        letters[num]["title"],
		letters[num]["to"],
        letters[num]["text"],
		letters[num]["from"],
		letters[num]["time"]
		);
		
        return 1;
}


