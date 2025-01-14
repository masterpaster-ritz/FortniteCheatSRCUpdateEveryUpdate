/*

Visual#9999, Updated by bunyip24#9999
*/

#include "../../Header Files/xorstr.h"
#include "../../imgui/imgui_xorstr.h"
#include "../Header Files/includes.h"
namespace Offsets {
	PVOID* uWorld = 0;

	namespace Engine {
		namespace World {
			DWORD OwningGameInstance = 0;
			DWORD Levels = 0;
		}

		namespace Level {
			DWORD AActors = 0x98;
		}

		namespace GameInstance {
			DWORD LocalPlayers = 0;
		}

		namespace Player {
			DWORD PlayerController = 0x30;
		}

		namespace Controller {
			DWORD ControlRotation = 0x280;
			PVOID SetControlRotation = 0;
			PVOID ClientSetRotation;
		}

		namespace PlayerController {
			DWORD AcknowledgedPawn = 0x298;
			DWORD PlayerCameraManager = 0x2B0;
		}

		namespace Pawn {
			DWORD PlayerState = 0x238;
		}

		namespace PlayerState {
			PVOID GetPlayerName = 0;
		}

		namespace Actor {
			DWORD RootComponent = 0x130;
			DWORD CustomTimeDilation = 0x98;
		}

		namespace Character {
			DWORD Mesh = 0x278;
		}

		namespace SceneComponent {
			DWORD RelativeLocation = 0x11C;
			DWORD ComponentVelocity = 0x140;
		}

		namespace StaticMeshComponent {
			DWORD ComponentToWorld = 0x1C0;
			DWORD StaticMesh = 0x480;
		}

		namespace SkinnedMeshComponent {
			DWORD CachedWorldSpaceBounds = 0x5A0;
		}
	}

	namespace FortniteGame {
		namespace FortPawn {
			DWORD bIsDBNO = 0x53A;
			DWORD bIsDying = 0x520;
			DWORD CurrentWeapon = 0x588;
		}

		namespace FortPickup {
			DWORD PrimaryPickupItemEntry = 0x280;
		}

		namespace FortItemEntry {
			DWORD ItemDefinition = 0x18;
		}

		namespace FortItemDefinition {
			DWORD DisplayName = 0x70;
			DWORD Tier = 0x54;
		}

		namespace FortPlayerStateAthena {
			DWORD TeamIndex = 0xE60;
		}

		namespace FortWeapon {
			DWORD WeaponData = 0x358;
			DWORD AmmoCount = 0x974;
		}

		namespace FortHoagieVehicle {
			DWORD BoostCooldown = 0x105C;
		}

		namespace FortWeaponItemDefinition {
			DWORD WeaponStatHandle = 0x7B8;
		}

		namespace FortProjectileAthena {
			DWORD FireStartLoc = 0x850;
		}

		namespace FortBaseWeaponStats {
			DWORD ReloadTime = 0;
		}

		namespace BuildingContainer {
			DWORD bAlreadySearched = 0xC59;
		}
	}

	namespace UI {
		namespace ItemCount {
			DWORD ItemDefinition = 0;
		}
	}

	BOOLEAN Initialize() {
		auto addr = Util::FindPattern(xorstr("\x48\x8B\x05\x00\x00\x00\x00\x4D\x8B\xC2"), xorstr("xxx????xxx"));
		if (!addr) {
			MessageBox(0, xorstr(L"Please contact an administrator and give the error code:\n0x08"), xorstr(L"Error"), 0);
			return FALSE;
		}

		uWorld = reinterpret_cast<decltype(uWorld)>(RELATIVE_ADDR(addr, 7));

		// SetControlRotation
		Engine::Controller::SetControlRotation = Util::FindObject(xorstr(L"/Script/Engine.Controller.SetControlRotation"));
		if (!Engine::Controller::SetControlRotation) {
			MessageBox(0, xorstr(L"Please contact an administrator and give the error code:\n0x09"), xorstr(L"Error"), 0);
			return FALSE;
		}

		// ClientSetRotation
		Engine::Controller::ClientSetRotation = Util::FindObject(xorstr(L"/Script/Engine.Controller.ClientSetRotation"));
		if (!Engine::Controller::ClientSetRotation) {
			MessageBox(0, xorstr(L"Please contact an administrator and give the error code:\n0x10"), xorstr(L"Error"), 0);
			return FALSE;
		}

		// GetPlayerName
		Engine::PlayerState::GetPlayerName = Util::FindObject(xorstr(L"/Script/Engine.PlayerState.GetPlayerName"));
		if (!Engine::PlayerState::GetPlayerName) {
			MessageBox(0, xorstr(L"Please contact an administrator and give the error code:\n0x11"), xorstr(L"Error"), 0);
			return FALSE;
		}

		Engine::World::Levels = 0x138;
		Engine::GameInstance::LocalPlayers = 0x38;
		Engine::World::OwningGameInstance = 0x180;
		Engine::Controller::ControlRotation = 0x288;
		Engine::PlayerController::PlayerCameraManager = 0x2B8;
		Engine::PlayerController::AcknowledgedPawn = 0x2A0;
		Engine::Pawn::PlayerState = 0x240;
		Engine::Actor::RootComponent = 0x130;
		Engine::Character::Mesh = 0x280;
		Engine::SceneComponent::RelativeLocation = 0x11C;
		Engine::SceneComponent::ComponentVelocity = 0x140;
		Engine::StaticMeshComponent::StaticMesh = 0x480;
		Engine::SkinnedMeshComponent::CachedWorldSpaceBounds = 0x600;
		Engine::Actor::CustomTimeDilation = 0x98;
		FortniteGame::FortPawn::bIsDBNO = 0x56E;
		FortniteGame::FortPawn::bIsDying = 0x540;
		FortniteGame::FortPlayerStateAthena::TeamIndex = 0xED0;
		FortniteGame::FortPickup::PrimaryPickupItemEntry = 0x2A8;
		FortniteGame::FortItemDefinition::DisplayName = 0x88;
		FortniteGame::FortItemDefinition::Tier = 0x6C;
		FortniteGame::FortItemEntry::ItemDefinition = 0x18;
		FortniteGame::FortPawn::CurrentWeapon = 0x5F0;
		FortniteGame::FortWeapon::WeaponData = 0x378;
		FortniteGame::FortWeaponItemDefinition::WeaponStatHandle = 0x820;
		FortniteGame::FortProjectileAthena::FireStartLoc = 0x878;
		FortniteGame::FortBaseWeaponStats::ReloadTime = 0xFC;
		FortniteGame::BuildingContainer::bAlreadySearched = 0xC81;


		return TRUE;



	}
}
