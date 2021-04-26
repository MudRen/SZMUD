/* channel block command..
 * author: ken@chinesemud.net
 * create time: 99-4-16
 */
 
#include <ansi.h>
#define valid_channels ({ "es", "rumor", "chat", "ldj", "shout","bidd","music" })

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	object ob;
	string who, channel;
	string *channels,*args;
	int i, flag;

	if( !arg ) {
		help(me);
		return 1;	
	}

        args = explode(arg," ");

	if( sizeof(args) < 1 ) {
		help(me);
		return 1;
	}
	if( sizeof(args) == 2 ) {
		who = args[0];
		channel = args[1];
		flag = 2;
	} else who = arg;
	
	ob = LOGIN_D->find_body(who);

	if (!ob) return notify_fail("����˲��ڣ�\n");

	if( !flag ) {
		channels = ob->query("channels");
		printf("%s(%s)��ǰ������Ƶ���У�\n",ob->query("name"),ob->query("id"));
		for( i=0;i<sizeof(channels);i++)
			printf("        %10s : %s\n",channels[i],
				(time() - ob->query("chblk_channel/" + channels[i]) <3600 ) ?
    HIR"�ر�"NOR : BOLD"����"NOR
				);
		printf("������Ƶ������ %d ����\n", sizeof(channels) );
		return 1;
	}

	flag = 0;

//	if (wizardp(ob)) return notify_fail("�㲻�ܹر���ʦ��Ƶ����\n");
        

        for( i=0;i<sizeof(valid_channels);i++ ) {
		if( channel == valid_channels[i] ) {
			flag = 1;
			break;
		}
	}
	if( channel == "all" )
		flag = 1;
	
	if( !flag ) {
		write("��ǰû�� " + channel + "���Ƶ����\n");
		return 1;
	}
/*
	if( time() - (int)ob->query("chblk_channel/" + channel) < 3600 )
		return notify_fail( ob->query("name")+"�����Ƶ���Ѿ��ǹرյġ�\n");
*/
	if( channel == "all" ) {
                        for( i=0;i<sizeof(valid_channels);i++ ) {
				ob->delete("chblk_channel/" + valid_channels[i], time() );
				printf("%s(%s)�� %s Ƶ���Ѿ����򿪡�\n",ob->query("name"),ob->query("id"),valid_channels[i]);
			}
	}
	else {
		ob->delete("chblk_channel/" + channel, time() );
		printf("%s(%s)�� %s Ƶ���Ѿ����򿪡�\n",ob->query("name"),ob->query("id"),channel);
	}
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : unchblk <ĳ��> [<Ƶ����>|all]

�������ĳ�˵�Ƶ�������û��Ƶ�����ʹ����кϷ�Ƶ����
<ĳ��>��Ҳ������Ƶ������
<Ƶ����> ������rumor �� chat 

HELP
    );
    return 1;

}

