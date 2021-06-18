// Code of ShenZhou
// wzfeng, 12/28/98
//ע�⣬����������㷨��û������������ȥ�ģ�����ÿһ���ͷһ��
//�޸�string chinese_time(int date)����



#include <ansi.h>
#include <localtime.h>
inherit ITEM;
inherit F_SAVE;
mapping *letters;
mapping letter;
nosave string *sym_di = ({ "��","��","��","î","��","��","��","δ","��","��","��","��" });
int set_owner(string id)
{
        set("owner_id", id);
        return restore();
}

string chinese_time(int date)
{
	mixed *local;
	int i;

	local = localtime(date);
	i = (local[LT_HOUR]+1) % 2 * 2 + local[LT_MIN] / 30;
	return sprintf("������%s��%s��%sʱ%s",
                chinese_number(local[LT_MON] + 1),
                chinese_number(local[LT_MDAY]),
                sym_di[((local[LT_HOUR] + 1) % 24) / 2],
		i?chinese_number((local[LT_HOUR]+1) % 2 * 2 +
		local[LT_MIN] / 30 ) + "��":"��");
}




string query_save_file()
{
        string id;

        if( !stringp(id = query("owner_id")) ) return 0;

        return DATA_DIR + "letter/" + id[0..0] + "/" + id;
}

void send_letter(mapping letter)
{
        if( !pointerp(letters) )
        {
         letters = ({ letter });
        }
        else letters += ({ letter });

}

void modify_letter(mapping letter)
{
        if( !pointerp(letters) )
        {
         letters = ({ letter });
        }
        else letters -= ({ letter });

}


void add_send_level(int a)
{
        int i;
        if(!i=sizeof(letters))
         return;
        letters[i-1]["send_level"]=a;
        return;


}
void add_send_time(int a)
{
        int i;
        if(!i=sizeof(letters))
         return;
        letters[i-1]["send_time"]=a;
        return;


}



void check(object me,object obj)
{
        object ob;
        int i,k;
		string str_time;
        string name_id;
        name_id=me->query("id");

         for(i=0;i<sizeof(letters);i++)
         {

		 ob=new("/d/city/obj/letter");
         ob->set("letter",letters[i]);
		 str_time=chinese_time(ob->query("letter/time"));

         switch( ob->query("letter/send_level"))
                {
                                case 1:
                                {

										ob->set("long",
"����һ���Ѿ���õ��ź�������д�ţ�\n"
+me->query("name")+"      ������\n"+
ob->query("letter/from")+"��������վת��\n"
"������վǩ����"+str_time+"��\n"
"��ɲ�(chai or open)������ķ��ᣬȡ���麯��\n");
										ob->set_name("�ź�", ({"xin han","letter"}));
                                        ob->set("send_level_time",600);
                                }

                                                  break;
                                case 2:
                                        {

                                        ob->set_name(YEL"�ź�"NOR, ({"xin han","letter"}));
										ob->set("long",
"����һ���Ѿ���õ��ź����䱳��մ��������ë������д��\n"
+me->query("name")+"      ������\n"+
ob->query("letter/from")+"��������վת��\n"
"������վǩ����"+str_time+"��\n"
"��ɲ�(chai or open)������ķ��ᣬȡ���麯��\n");
										ob->set("send_level_time",300);

                                }

                                                  break;
                                case 3:
									{
                                        ob->set_name(HIR"�ź�"NOR, ({"xin han","letter"}));
                                       	ob->set("long",
"����һ���Ѿ���õĲ��ң�����װ���麯���䱳��մ�������\n"
"ë������д�ţ�\n"
+me->query("name")+"      ������\n"+
ob->query("letter/from")+"��������վת��\n"
"������վǩ����"+str_time+"��\n"
"��ɲ�(chai or open)������ķ��ᣬȡ���麯��\n");
										ob->set("send_level_time",0);
									}
                                                  break;

                }
                if(ob->query("letter/send_time")+ob->query("send_level_time")<time())
                 {
                 //���Է���
                 ob->move(me);
                 modify_letter(letters[i]);
                 save();
                 k++;
                 }
                 else
                 {
                         //ʱ��δ��.
                         destruct(ob);
                 }
        }

        if(k)
        {

                obj->do_emote(ob->query("letter/to"));
                tell_object(me,CYN"һ����ʹ���˹�����\n"NOR);
                tell_object(me,CYN"��ʹ���㱨ȭ˵�����������������ż�����С���պá���\n"NOR);
                tell_object(me,CYN"��ʹ�������ó�һ���������������\n"NOR);
                tell_object(me,CYN"��ʹ����˵��������ʹ�͵������»��й����������и��ˡ�\n"NOR);
                tell_object(me,CYN"��ʹ���˳�ȥ��\n"NOR);
        }

}

void create()
{
        set_name("��", ({"xin", "letter"}));
        set_weight(1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���Ѿ�д�õ��ţ�����ö�(read letter)�����������ݡ�\n");
                set("unit", "��");

		        set("can_read_letter",1);

                }
}

void init ()
{
        add_action("do_read", "read");
        add_action("do_read", "��");
}

int do_read(string arg)
{
     object ob,ob_letter;
      int i;
     ob=this_object();

	 if(!arg) return notify_fail("��Ҫ��ʲô�ż���\n");

	 ob_letter = present(arg, this_player());

	 if(!ob_letter)
            return notify_fail("�����Ϻ���û������ż���\n");
        if(!ob_letter->query("can_read_letter"))
                return notify_fail("�Բ������޷�������������κζ�����\n");



        if(!i=sizeof(letters))
                return notify_fail("��ȡʧ�ܡ�\n");

        printf("�����ű��⡿��%s\n�������ˡ���%s\n���ż����ݡ���\n%s\n\t\t%sд��%s\n\n\n",
        letters[i-1]["title"],
		letters[i-1]["to"],
        letters[i-1]["text"],
		letters[i-1]["from"],
		chinese_time((letters[i-1]["time"]))
		);

        return 1;
}
